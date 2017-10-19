<?php
/**
 * sysPass
 *
 * @author    nuxsmin
 * @link      http://syspass.org
 * @copyright 2012-2017, Rubén Domínguez nuxsmin@$syspass.org
 *
 * This file is part of sysPass.
 *
 * sysPass is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * sysPass is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 *  along with sysPass.  If not, see <http://www.gnu.org/licenses/>.
 */

namespace SP\Modules\Web\Controllers;

use SP\Controller\ControllerBase;
use SP\Core\SessionFactory;
use SP\Core\SessionUtil;
use SP\Html\Html;
use SP\Http\Response;
use SP\Log\Log;
use SP\Modules\Web\Controllers\Helpers\LayoutHelper;
use SP\Services\LoginService;
use SP\Util\Json;

/**
 * Class LoginController
 *
 * @package SP\Modules\Web\Controllers
 */
class LoginController extends ControllerBase
{
    /**
     * Login action
     *
     * @throws \InvalidArgumentException
     */
    public function loginAction()
    {
        $LoginService = new LoginService($this->config, $this->session, $this->theme, $this->eventDispatcher);
        return Json::returnJson($LoginService->doLogin());
    }

    /**
     * Logout action
     */
    public function logoutAction()
    {
        if ($this->session->isLoggedIn()) {
            $inactiveTime = abs(round((time() - SessionFactory::getLastActivity()) / 60, 2));
            $totalTime = abs(round((time() - SessionFactory::getStartActivity()) / 60, 2));

            $Log = new Log();
            $LogMessage = $Log->getLogMessage();
            $LogMessage->setAction(__('Finalizar sesión', false));
            $LogMessage->addDetails(__('Usuario', false), SessionFactory::getUserData()->getUserLogin());
            $LogMessage->addDetails(__('Tiempo inactivo', false), $inactiveTime . ' min.');
            $LogMessage->addDetails(__('Tiempo total', false), $totalTime . ' min.');
            $Log->writeLog();

            SessionUtil::cleanSession();
            SessionFactory::setLoggedOut(true);

            $LayoutHelper = new LayoutHelper($this->view, $this->config, $this->session, $this->eventDispatcher);
            $LayoutHelper->setPage('logout');
            $LayoutHelper->initBody();

            $this->view->addTemplate('logout');

            $this->view->addPartial('body-footer');
            $this->view->addPartial('body-end');
            $this->view();
        } else {
            Response::redirect('index.php?r=login');
        }
    }

    /**
     * Index action
     */
    public function indexAction()
    {
        $LayoutHelper = new LayoutHelper($this->view, $this->config, $this->session, $this->eventDispatcher);
        $LayoutHelper->setPage('login');
        $LayoutHelper->initBody();

        if (SessionFactory::getLoggedOut() === true) {
            SessionFactory::setLoggedOut();

            $this->view->assign('loggedOut', 1);
        } else {
            $this->view->assign('loggedOut', 0);
        }

        $this->view->addTemplate('login');

        $this->view->addPartial('body-footer');
        $this->view->addPartial('body-end');

        $this->view->assign('useLayout', false);
        $this->view->assign('mailEnabled', $this->configData->isMailEnabled());
        $this->view->assign('updated', SessionFactory::getAppUpdated());

        SessionFactory::setAppUpdated(false);

        $getParams = [];

        // Comprobar y parsear los parámetros GET para pasarlos como POST en los inputs
        if (count($_GET) > 0) {
            foreach ($_GET as $param => $value) {
                $getParams['g_' . Html::sanitizeFull($param)] = Html::sanitizeFull($value);
            }
        }

        $this->view->assign('getParams', $getParams);
        $this->view();
    }
}