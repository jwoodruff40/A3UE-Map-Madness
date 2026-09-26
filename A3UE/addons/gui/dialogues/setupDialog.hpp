
class A3UE_MM_setupDialog : A3A_SetupDialog
{
    class Controls : Controls
    {
        class TitlebarText : TitlebarText {};
        class TabButtons : TabButtons {};
        class LoadgameTab : LoadgameTab
        {
            class Controls : Controls
            {
                class SavedGamesLabel : SavedGamesLabel {};
                class SavedGamesBackground: SavedGamesBackground {};
                class SavedGamesHeader : SavedGamesHeader {};
                class SavedGamesTable : SavedGamesTable {};

                class SaveNameLabel : SaveNameLabel {};
                class SaveNameEditBox : SaveNameEditBox {};

                class GameOptionsGroup : GameOptionsGroup {
                    h = 45 * GRID_H;

                    class controls : controls {
                        class GameOptions : GameOptions {};
                        class GameOptionsBackground : GameOptionsBackground {};
                        class NewGameCheck : NewGameCheck {};
                        class NewGameText : NewGameText {};
                        class CopyGameCheck : CopyGameCheck {};
                        class CopyGameText : CopyGameText {};
                        class OldParamsCheck : OldParamsCheck {};
                        class OldParamsText : OldParamsText {};
                        class NewNamespaceCheck : NewNamespaceCheck {};
                        class NewNamespaceText : NewNamespaceText {};
                        class SetHQPosButton : SetHQPosButton
                        {
                            y = 40 * GRID_H;
                        };
                        
                        // Map Madness Addition
                        class MapMadnessButton : A3A_Button {
                            idc = A3A_IDC_SETUP_MAPMADNESSBUTTON;
                            text = $STR_A3UE_MM_dialogs_map_madness;
                            onButtonClick = "['editMap'] call A3A_fnc_setupLoadgameTab";
                            x = 0;
                            y = 32 * GRID_H;
                            w = 30 * GRID_W;
                            h = 5 * GRID_H;
                        };
                    };
                };

                class DeleteButton : DeleteButton {};
                class RenameButton : RenameButton {};
            };
        };
        class FactionsTab : FactionsTab {};
        class ParamsTab : ParamsTab {};
    };
};

class A3UE_MM_EditMapDialog : A3A_SetupHQPosDialog
{
    idd = A3A_IDD_EDITMAPDIALOG;
    onLoad = "['onLoad'] spawn A3A_fnc_setupEditMapDialog";
    onUnload = "['onUnload'] call A3A_fnc_setupEditMapDialog";

    class ControlsBackground : ControlsBackground
    {
        class HQMap : HQMap
        {
            idc = -1;
            onMouseButtonUp = "['mouseUp', _this] spawn A3A_fnc_setupEditMapDialog";
            x = safeZoneX;
            y = safeZoneY;
            w = safeZoneW;
            h = safeZoneH;
        };
    };
    class Controls : Controls
    {
        class CloseButton : CloseButton
        {
            idc = -1;
            text = $STR_antistasi_dialogs_hqpos_close;
            onButtonClick = "closeDialog 0";
            x = safeZoneX;
            y = safeZoneY;
            w = 30 * GRID_W;
            h = 6 * GRID_H;
        };

        class MapZonesGroup : A3A_ControlsGroupNoScrollbars
        {
            x = safeZoneX;
            y = 8 * GRID_H;
            w = 30 * GRID_W;
            h = 40 * GRID_H;

            class Controls
            {
                class MapZonesText : A3A_Text
                {
                    idc = -1;
                    text = $STR_A3UE_MM_dialogs_map_zones;
                    x = 0;
                    y = 0;
                    w = 30 * GRID_W;
                    h = 5 * GRID_H;
                    colorBackground[] = A3A_COLOR_BUTTON_BACKGROUND;
                    style = ST_CENTER + ST_UPPERCASE;
                    font = A3A_BUTTON_FONT;
                };
                class MapZonesBackground : A3A_Background
                {
                    idc = -1;
                    x = 0;
                    y = 0;
                    w = 30 * GRID_W;
                    h = 40 * GRID_H;
                };
                class OutpostsCheck : A3A_Checkbox
                {
                    idc = A3A_IDC_EDITMAP_OUTPOSTSCHECKBOX;
                    checked = 1;
                    onCheckedChanged = "['updateZoneVisibility'] call A3A_fnc_setupEditMapDialog";
                    x = 0;
                    y = 6 * GRID_H;
                    w = 4 * GRID_W;
                    h = 4 * GRID_H;
                };
                class OutpostsText : A3A_Text
                {
                    idc = -1;
                    text = $STR_A3UE_MM_dialogs_outposts;
                    x = 4 * GRID_W;
                    y = 6 * GRID_H;
                    w = 26 * GRID_W;
                    h = 4 * GRID_H;
                };
                class MilbasesCheck : OutpostsCheck
                {
                    idc = A3A_IDC_EDITMAP_MILBASESCHECKBOX;
                    y = 12 * GRID_H;
                };
                class MilbasesText : OutpostsText
                {
                    text = $STR_A3UE_MM_dialogs_milbases;
                    y = 12 * GRID_H;
                };
                class AirportsCheck : OutpostsCheck
                {
                    idc = A3A_IDC_EDITMAP_AIRPORTSCHECKBOX;
                    y = 18 * GRID_H;
                };
                class AirportsText : OutpostsText
                {
                    text = $STR_A3UE_MM_dialogs_airports;
                    y = 18 * GRID_H;
                };
                class ResourcesCheck : OutpostsCheck
                {
                    idc = A3A_IDC_EDITMAP_RESOURCESCHECKBOX;
                    y = 24 * GRID_H;
                };
                class ResourcesText : OutpostsText
                {
                    text = $STR_A3UE_MM_dialogs_resources;
                    y = 24 * GRID_H;
                };
                class FactoriesCheck : OutpostsCheck
                {
                    idc = A3A_IDC_EDITMAP_FACTORIESCHECKBOX;
                    y = 30 * GRID_H;
                };
                class FactoriesText : OutpostsText
                {
                    text = $STR_A3UE_MM_dialogs_factories;
                    y = 30 * GRID_H;
                };
            };
        };
    };
};
