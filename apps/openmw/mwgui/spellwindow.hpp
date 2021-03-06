#ifndef MWGUI_SPELLWINDOW_H
#define MWGUI_SPELLWINDOW_H

#include "windowpinnablebase.hpp"

#include "spellmodel.hpp"

namespace MWGui
{
    class SpellIcons;
    class SpellView;

    class SpellWindow : public WindowPinnableBase, public NoDrop
    {
    public:
        SpellWindow(DragAndDrop* drag);
        virtual ~SpellWindow();

        void updateSpells();

        void onFrame(float dt) override;

        /// Cycle to next/previous spell
        void cycle(bool next);

    protected:
        MyGUI::Widget* mEffectBox;

        std::string mSpellToDelete;

        void onEnchantedItemSelected(MWWorld::Ptr item, bool alreadyEquipped);
        void onSpellSelected(const std::string& spellId);
        void onModelIndexSelected(SpellModel::ModelIndex index);
        void onFilterChanged(MyGUI::EditBox *sender);
        void onDeleteClicked(MyGUI::Widget *widget);
        void onDeleteSpellAccept();
        void askDeleteSpell(const std::string& spellId);

        void onPinToggled() override;
        void onTitleDoubleClicked() override;
        void onOpen() override;

        SpellView* mSpellView;
        SpellIcons* mSpellIcons;
        MyGUI::EditBox* mFilterEdit;

    private:
        float mUpdateTimer;
    };
}

#endif
