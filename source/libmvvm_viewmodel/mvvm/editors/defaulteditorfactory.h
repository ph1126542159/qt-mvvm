// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef MVVM_EDITORS_DEFAULTEDITORFACTORY_H
#define MVVM_EDITORS_DEFAULTEDITORFACTORY_H

#include <map>
#include <memory>
#include <mvvm/editors/editorbuilders.h>
#include <mvvm/interfaces/editorfactoryinterface.h>

namespace ModelView
{

//! Abstract editor factory for ViewModelDelegate.
//! Creates cell editors for Qt trees and tables basing on model index. Cell editor is
//! Qt widget intended for editing DATA role of some SessionItem.

class MVVM_VIEWMODEL_EXPORT AbstractEditorFactory : public EditorFactoryInterface
{
public:
    std::unique_ptr<CustomEditor> createEditor(const QModelIndex& index) const override;

protected:
    virtual std::unique_ptr<CustomEditor> createItemEditor(const SessionItem& item) const = 0;

    void registerBuilder(const std::string& name, EditorBuilders::builder_t builder);
    EditorBuilders::builder_t findBuilder(const std::string& name) const;

    std::map<std::string, EditorBuilders::builder_t> m_nameToBuilderMap;
};

//! Editor factory for cell editors in Qt trees and tables, relies on EDITORTYPE role stored
//! on board of SessionItem.

class MVVM_VIEWMODEL_EXPORT RoleDependentEditorFactory : public AbstractEditorFactory
{
public:
    RoleDependentEditorFactory();

protected:
    std::unique_ptr<CustomEditor> createItemEditor(const SessionItem& item) const override;
};

//! Editor factory for cell editors in Qt trees and tables, relies on variant type stored as
//! DATA role on board of SessionItem.

class MVVM_VIEWMODEL_EXPORT VariantDependentEditorFactory : public AbstractEditorFactory
{
public:
    VariantDependentEditorFactory();

protected:
    std::unique_ptr<CustomEditor> createItemEditor(const SessionItem& item) const override;
};

//! Default editor factory for cell editors in Qt trees and tables.
//! Internaly it uses two factories

class MVVM_VIEWMODEL_EXPORT DefaultEditorFactory : public EditorFactoryInterface
{
public:
    DefaultEditorFactory();

    std::unique_ptr<CustomEditor> createEditor(const QModelIndex& index) const override;

private:
    std::unique_ptr<RoleDependentEditorFactory> m_roleDependentFactory;
    std::unique_ptr<VariantDependentEditorFactory> m_variantDependentFactory;
};

} // namespace ModelView

#endif // MVVM_EDITORS_DEFAULTEDITORFACTORY_H
