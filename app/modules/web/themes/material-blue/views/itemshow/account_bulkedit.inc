<?php
/**
 * @var \SP\Core\UI\ThemeIcons               $icons
 * @var \SP\Mvc\View\Components\SelectItem[] $clients
 * @var \SP\Mvc\View\Components\SelectItem[] $categories
 * @var \SP\Mvc\View\Components\SelectItem[] $users
 * @var \SP\Mvc\View\Components\SelectItem[] $userGroups
 * @var \SP\Mvc\View\Components\SelectItem[] $tags
 */
?>

<div id="box-popup">
    <h2 class="center"><?php echo $header; ?><i class="btn-popup-close material-icons">close</i></h2>

    <div class="mdl-tabs mdl-js-tabs mdl-js-ripple-effect">
        <div class="mdl-tabs__tab-bar">
            <a href="#general-panel" class="mdl-tabs__tab is-active"><?php echo __('General'); ?></a>
            <a href="#permission-panel" class="mdl-tabs__tab"><?php echo __('Permisos'); ?></a>
            <a href="#other-panel" class="mdl-tabs__tab"><?php echo __('Otros'); ?></a>
        </div>

        <form method="post" name="frmAccountBulkEdit" id="frmAccountBulkEdit" class="form-action"
              data-onsubmit="appMgmt/save"
              data-action-route="<?php echo isset($route) ? $route : ''; ?>"
              data-activetab="<?php echo isset($activeTab) ? $activeTab : ''; ?>"
              data-hash="">

            <div class="mdl-tabs__panel is-active" id="general-panel">
                <table class="popup-data">
                    <tbody>
                    <tr>
                        <td class="descField"><?php echo __('Cliente'); ?></td>
                        <td class="valField">
                            <div class="lowres-title"><?php echo __('Cliente'); ?></div>

                            <select id="client_id" name="client_id" class="select-box">
                                <option value=""><?php echo __('Seleccionar Cliente'); ?></option>
                                <?php foreach ($clients as $client): ?>
                                    <option
                                            value="<?php echo $client->getId(); ?>"><?php echo $client->getName(); ?></option>
                                <?php endforeach; ?>
                            </select>
                        </td>
                    </tr>

                    <tr>
                        <td class="descField"><?php echo __('Categoría'); ?></td>
                        <td class="valField">
                            <div class="lowres-title"><?php echo __('Categoría'); ?></div>

                            <select id="category_id" name="category_id" class="select-box">
                                <option value=""><?php echo __('Seleccionar Categoría'); ?></option>
                                <?php foreach ($categories as $category): ?>
                                    <option
                                            value="<?php echo $category->getId(); ?>"><?php echo $category->getName(); ?></option>
                                <?php endforeach; ?>
                            </select>
                        </td>
                    </tr>

                    <tr>
                        <td class="descField"><?php echo __('Creador'); ?></td>
                        <td class="valField">
                            <div class="lowres-title"><?php echo __('Creador'); ?></div>

                            <select id="owner_id" name="owner_id" class="select-box">
                                <option value=""><?php echo __('Seleccionar Usuario'); ?></option>
                                <?php foreach ($users as $user): ?>
                                    <option
                                            value="<?php echo $user->getId(); ?>"><?php echo $user->getName(); ?></option>
                                <?php endforeach; ?>
                            </select>
                        </td>
                    </tr>

                    <tr>
                        <td class="descField"><?php echo __('Grupo Principal'); ?></td>
                        <td class="valField">
                            <div class="lowres-title"><?php echo __('Grupo Principal'); ?></div>

                            <select id="main_usergroup_id" name="main_usergroup_id" class="select-box">
                                <option value=""><?php echo __('Seleccionar Grupo'); ?></option>
                                <?php foreach ($userGroups as $group): ?>
                                    <option
                                            value="<?php echo $group->getId(); ?>"><?php echo $group->getName(); ?></option>
                                <?php endforeach; ?>
                            </select>
                        </td>
                    </tr>

                    <tr>
                        <td class="descField"><?php echo __('Etiquetas'); ?></td>
                        <td class="valField">
                            <select id="tags" name="tags[]" multiple="multiple"
                                    class="select-box-tags">
                                <option value=""><?php echo __('Seleccionar Etiquetas'); ?></option>
                                <?php foreach ($tags as $tag): ?>
                                    <option value="<?php echo $tag->getId(); ?>"><?php echo $tag->getName(); ?></option>
                                <?php endforeach; ?>
                            </select>
                        </td>
                    </tr>
                    </tbody>
                </table>
            </div>

            <div class="mdl-tabs__panel" id="permission-panel">
                <table class="popup-data">
                    <tbody>
                    <tr>
                        <td class="descField"><?php echo __('Usuarios'); ?></td>
                        <td class="valField">
                            <div class="account-permissions">
                                <div class="tag-list-box">
                                    <select id="other_users_view" name="other_users_view[]"
                                            multiple="multiple" class="select-box-tags">
                                        <option value=""><?php echo __('Seleccionar Usuarios'); ?></option>
                                        <?php foreach ($users as $user): ?>
                                            <option
                                                    value="<?php echo $user->getId(); ?>"><?php echo $user->getName(); ?></option>
                                        <?php endforeach; ?>
                                    </select>

                                    <i class="material-icons select-icon"
                                       title="<?php echo __('Ver'); ?>"><?php echo $icons->getIconView()->getIcon(); ?></i>
                                </div>

                                <label class="mdl-checkbox mdl-js-checkbox mdl-js-ripple-effect"
                                       for="clear_permission_users_view">
                                    <input type="checkbox" id="clear_permission_users_view" class="mdl-checkbox__input"
                                           name="clear_permission_users_view">
                                    <span class="mdl-checkbox__label"><?php echo __('Eliminar'); ?></span>
                                </label>

                                <div class="tag-list-box">
                                    <select id="other_users_edit" name="other_users_edit[]"
                                            multiple="multiple" class="select-box-tags">
                                        <option value=""><?php echo __('Seleccionar Usuarios'); ?></option>
                                        <?php foreach ($users as $user): ?>
                                            <option
                                                    value="<?php echo $user->getId(); ?>"><?php echo $user->getName(); ?></option>
                                        <?php endforeach; ?>
                                    </select>

                                    <i class="material-icons select-icon"
                                       title="<?php echo __('Editar'); ?>"><?php echo $icons->getIconEdit()->getIcon(); ?></i>
                                </div>

                                <label class="mdl-checkbox mdl-js-checkbox mdl-js-ripple-effect"
                                       for="clear_permission_users_edit">
                                    <input type="checkbox" id="clear_permission_users_edit" class="mdl-checkbox__input"
                                           name="clear_permission_users_edit">
                                    <span class="mdl-checkbox__label"><?php echo __('Eliminar'); ?></span>
                                </label>
                            </div>
                        </td>
                    </tr>

                    <tr>
                        <td class="descField"><?php echo __('Grupos'); ?></td>
                        <td class="valField">
                            <div class="account-permissions">
                                <div class="tag-list-box">
                                    <select id="other_usergroups_view" name="other_usergroups_view[]"
                                            multiple="multiple" class="select-box-tags">
                                        <option value=""><?php echo __('Seleccionar Grupos'); ?></option>
                                        <?php foreach ($userGroups as $userGroup): ?>
                                            <option
                                                    value="<?php echo $userGroup->getId(); ?>"><?php echo $userGroup->getName(); ?></option>
                                        <?php endforeach; ?>
                                    </select>

                                    <i class="material-icons select-icon"
                                       title="<?php echo __('Ver'); ?>"><?php echo $icons->getIconView()->getIcon(); ?></i>
                                </div>

                                <label class="mdl-checkbox mdl-js-checkbox mdl-js-ripple-effect"
                                       for="clear_permission_usergroups_view">
                                    <input type="checkbox" id="clear_permission_usergroups_view" class="mdl-checkbox__input"
                                           name="clear_permission_usergroups_view">
                                    <span class="mdl-checkbox__label"><?php echo __('Eliminar'); ?></span>
                                </label>

                                <div class="tag-list-box">
                                    <select id="other_usergroups_edit" name="other_usergroups_edit[]"
                                            multiple="multiple" class="select-box-tags">
                                        <option value=""><?php echo __('Seleccionar Grupos'); ?></option>
                                        <?php foreach ($userGroups as $userGroup): ?>
                                            <option
                                                    value="<?php echo $userGroup->getId(); ?>"><?php echo $userGroup->getName(); ?></option>
                                        <?php endforeach; ?>
                                    </select>

                                    <i class="material-icons select-icon"
                                       title="<?php echo __('Editar'); ?>"><?php echo $icons->getIconEdit()->getIcon(); ?></i>
                                </div>

                                <label class="mdl-checkbox mdl-js-checkbox mdl-js-ripple-effect"
                                       for="clear_permission_usergroups_edit">
                                    <input type="checkbox" id="clear_permission_usergroups_edit" class="mdl-checkbox__input"
                                           name="clear_permission_usergroups_edit">
                                    <span class="mdl-checkbox__label"><?php echo __('Eliminar'); ?></span>
                                </label>
                            </div>
                        </td>
                    </tr>
                    </tbody>
                </table>
            </div>

            <div class="mdl-tabs__panel" id="other-panel">
                <table class="popup-data">
                    <tbody>
                    <tr>
                        <td></td>
                        <td>
                            <ul class="other-list-action mdl-list">
                                <li class="mdl-list__item mdl-list__item--two-line">
                                    <div class="mdl-switch__box">
                                        <label class="mdl-checkbox mdl-js-checkbox mdl-js-ripple-effect"
                                               for="delete_history">
                                            <input type="checkbox" id="delete_history" class="mdl-checkbox__input"
                                                   name="delete_history">
                                        </label>
                                    </div>

                                    <span class="mdl-list__item-primary-content">
                                        <span><?php echo __('Eliminar Historial'); ?></span>
                                        <span class="mdl-list__item-sub-title">
                                            <?php echo __('Eliminar Historial'); ?>
                                        </span>
                                    </span>
                                </li>
                            </ul>
                        </td>
                    </tr>

                    <tr>
                        <td class="descField"><?php echo __('Fecha Caducidad Clave'); ?></td>
                        <td class="valField">
                            <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                                <input id="password_date_expire" name="password_date_expire" type="date"
                                       class="mdl-textfield__input mdl-color-text--indigo-400 password-datefield__input"
                                       data-dst-unix="password_date_expire_unix">
                                <input type='hidden' name='password_date_expire_unix' value=""/>
                                <label class="mdl-textfield__label"
                                       for="password_date_expire"><?php echo __('Fecha'); ?></label>
                            </div>
                            <i class="material-icons btn-action"
                               title="<?php echo __('Seleccionar Fecha'); ?>">date_range</i>
                        </td>
                    </tr>

                    </tbody>
                </table>
            </div>

            <input type="hidden" name="itemsId" value="<?php echo implode(',', $itemsId); ?>">
            <input type="hidden" name="isAjax" value="1">
        </form>
    </div>

    <div class="action-in-box">
        <button form="frmAccountBulkEdit"
                class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored <?php echo $icons->getIconSave()->getClassButton(); ?>"
                title="<?php echo $icons->getIconSave()->getTitle(); ?>">
            <i class="material-icons"><?php echo $icons->getIconSave()->getIcon(); ?></i>
        </button>
    </div>
</div>
<script type="text/javascript">
    sysPassApp.sk.set("<?php echo $sk; ?>");
</script>