/* See LICENSE file for copyright and license details. */


/* alt-tab configuration */
static const unsigned int tabModKey       = 0x40; /* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey     = 0x17; /* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY         = 1;    /* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX         = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab         = 600;  /* tab menu width */
static const unsigned int maxHTab         = 200;  /* tab menu height */

// APPEARANCE _________________________________________________________________________________________________________________________//

//*********************************************//************************************************************//
static const unsigned int borderpx       = 2;  // border pixel of windows                                    //
static const unsigned int gappx          = 8; // gaps between windows                                       //
static const unsigned int snap           = 32; // snap pixel                                                 //
//*********************************************//************************************************************//
static const unsigned int systraypinning = 0;  // systray pin                                                //
static const unsigned int systrayonleft  = 0;  // systray on the left                                        //
static const unsigned int systrayspacing = 3;  // systray spacing                                            //
static const int systraypinningfailfirst = 1;  // if pinning failed try display systray on the first monitor //
//*********************************************//************************************************************//
static const int showsystray             = 1;  // Enable Systray                                             //
static const int showbar                 = 1;  // Enable Top Bar                                             //
static const int topbar                  = 1;  // Enable Bottom Bar ??                                       //
//*********************************************//************************************************************//

static const char *fonts[]               = { "FiraCode Nerd Font:size=10" }; // Fonts

//** Colors ******************************************//
//static const char col_gray1[]            = "#3b4252"; //
//static const char col_gray2[]            = "#434c5e"; //
//static const char col_gray3[]            = "#d8dee9"; //
//static const char col_gray4[]            = "#e5e9f0"; //
//static const char col_cyan[]             = "#88c0d0"; //
//****************************************************//

//static const char *colors[][3]           = {
//[Scheme]     = { fg,        bg,        border     },
//  [SchemeNorm] = { col_gray3, col_gray1, col_gray2  },
//  [SchemeSel]  = { col_cyan,  col_gray1, col_cyan   },
//};

static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selbgcolor,  normbgcolor,  selbordercolor  },
};

// TAGS _______________________________________________________________________________________________________________________________//
static const char *tags[] = { "󰖟", "", "", "󰕧", "󰝚", "", "","󰭹", "󰇘" };

// RULES ______________________________________________________________________________________________________________________________//
static const Rule rules[] = {
//  { class,      instance,    title,       tags mask,     isfloating,   monitor },
    { "Gimp",     NULL,        NULL,        0,             0,            -1      },
    { "Firefox",  NULL,        NULL,        1 << 8,        0,            -1      },
};


// LAYOUT _____________________________________________________________________________________________________________________________//

//**************************************//*******************************************//
static const float mfact        = 0.55; // Master Stack Default Size [0.5 -> 0.95]   //
static const int nmaster        = 1;    // Master Stack Windows                      //
static const int resizehints    = 1;    // BOOL respect size hints in tiled resizals //
static const int lockfullscreen = 1;    // BOOL force focus on the fullscreen window //
//**************************************//*******************************************//

static const Layout layouts[] = { // Layout Symbols
  //************************//*******************//
  { "[]=",      tile    },  // Tiling   | Layout //
  { "><>",      NULL    },  // Floating | Layout //
  { "|||",      col     },  // Columns  | Layout //
  { "[M]",      monocle },  // Monocle  | Layout //
  //************************//*******************//
};

// KEY DEFINITIONS ____________________________________________________________________________________________________________________//

#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG)												\
  &((Keychord){1, {{MODKEY, KEY}},								view,           {.ui = 1 << TAG} }), \
  &((Keychord){1, {{MODKEY|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }), \
  &((Keychord){1, {{MODKEY|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }), \
  &((Keychord){1, {{MODKEY|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} }),


// helper for spawning shell commands in the pre dwm-5.0 fashion 
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/zsh", "-c", cmd, NULL } }

//* COMMANDS *******************************************************************************************//************************//
static const char *xkbmap[]        = { "/home/mohannadk28/.local/share/dwm/scripts/langswitch", NULL };             // Change Keyboard Layout //
static const char *runprompt[]     = { "/home/mohannadk28/.local/share/dwm/scripts/launch", NULL };                 // Run Prompt             //
static const char *lockcmd[]       = { "/home/mohannadk28/.local/share/dwm/scripts/lock", NULL};                    // Lock Screen            //
//******************************************************************************************************//************************//
static const char *webcmd[]        = { "/home/mohannadk28/.local/share/dwm/defapps/web", NULL };                    // Open | Web Browser     //
static const char *termcmd[]       = { "/home/mohannadk28/.local/share/dwm/defapps/term", NULL };                   // Open | Terminal        //
static const char *filecmd[]       = { "/home/mohannadk28/.local/share/dwm/defapps/file", NULL };                   // Open | File Manager    //
static const char *codecmd[]       = { "/home/mohannadk28/.local/share/dwm/defapps/code", NULL };                   // Open | Code Editor     //
static const char *keepasscmd[]       = { "/home/mohannadk28/.local/share/dwm/defapps/keepass", NULL };             // Open | KeePass Client  //
//******************************************************************************************************************//************************//
static const char *prtselcmd[]     = { "/home/mohannadk28/.local/share/dwm/scripts/screenshot", "select", NULL };   // Screenshot | Selection //
static const char *prtfscmd[]      = { "/home/mohannadk28/.local/share/dwm/scripts/screenshot", NULL };             // Screenshot | Screen    //
//******************************************************************************************************************//************************//
static const char *volupcmd[]      = { "amixer", "set", "Master", "5%+", NULL };                        // Volume | Up            //
static const char *voldowncmd[]    = { "amixer", "set", "Master", "5%-", NULL };                        // Volume | Down          //
static const char *volmcmd[]       = { "amixer", "set", "Master", "0", NULL };                          // Volume | Mute          //
//******************************************************************************************************//************************//
static const char *brightupcmd[]   = { "brightnessctl", "s", "10%+", NULL };                            // Brightness | Up        //
static const char *brightdowncmd[] = { "brightnessctl", "s", "10&-", NULL };                            // Brightness | Down      //
//******************************************************************************************************//************************//
static const char *byecmd[]        = { "/home/mohannadk28/.local/share/dwm/scripts/bye", NULL };                    // Bye :D                 //
static const char *webmarkcmd[]    = { "/home/mohannadk28/.pixelfiles/scripts-pixelfiles/dmenu/webmark", NULL };    // WebMark                //
static const char *wallchangecmd[] = { "/home/mohannadk28/.pixelfiles/scripts-pixelfiles/dmenu/wallchange", NULL }; // WallChange             //
static const char *ambientercmd[]  = { "/home/mohannadk28/.pixelfiles/scripts-pixelfiles/dmenu/ambienter", NULL };  // Ambienter              //
//******************************************************************************************************//************************//
static const char *emojicmd[]      = { "/home/mohannadk28/.pixelfiles/scripts-pixelfiles/dmenu/emoji", NULL };      // Emoji Menu             //
static const char *kamojicmd[]     = { "/home/mohannadk28/.pixelfiles/scripts-pixelfiles/dmenu/kamoji", NULL };     // Kamoji Menu            //
//******************************************************************************************************//************************//

// BINDINGS ___________________________________________________________________________________________________________________________//
#include "shiftview.c" // Shiftview Plugin 
#include <X11/XF86keysym.h> // XF86 Key Definitions


static Keychord *keychords[] = { // Keyborad Bindings

  //***************************************************************************************************//
  // Applications                                                                        | _ | + | x | //
  //****************************************************************************//*********************//
  &((Keychord){ 1,           {{ MODKEY, XK_r }}, spawn, { .v = runprompt } } ), // Run Prompt          //
  &((Keychord){ 1, {{ MODKEY|ShiftMask, XK_l }}, spawn, { .v = lockcmd   } } ), // Lock Screen         //
  //****************************************************************************//*********************//
  &((Keychord){ 1,           {{ MODKEY, XK_x }}, spawn, { .v = termcmd   } } ), // Open | Terminal     //
  &((Keychord){ 1,           {{ MODKEY, XK_e }}, spawn, {.v = filecmd    } } ), // Open | File Manager //
  &((Keychord){ 1,           {{ MODKEY, XK_b }}, spawn, {.v = webcmd     } } ), // Open | Web Browser  //
  &((Keychord){ 1,           {{ MODKEY, XK_z }}, spawn, {.v = codecmd    } } ), // Open | Code Editor  //
  //****************************************************************************//*********************//
  
  //*********************************************************************************************************************************//
  // Window                                                                                                            | _ | + | x | //
  //******************************************************************************//*************************************************//
  &((Keychord){ 1,            {{ MODKEY, XK_w}}, killclient,     {0        } } ), // Closes The Foucused Window                      //
  //******************************************************************************//*************************************************//
  &((Keychord){ 1,            {{ MODKEY, XK_j}}, focusstack,     {.i = +1  } } ), // Shift Focus to | the Previous Window in the Tag //
  &((Keychord){ 1,            {{ MODKEY, XK_k}}, focusstack,     {.i = -1  } } ), // Shift Focus to | the Next Window in the Tag     //
  //******************************************************************************//*************************************************//
  &((Keychord){ 1,         {{ ALTKEY, XK_Tab }}, altTabStart,    {0        } } ), // Cycles Between The Windows in The Tag           //
  //********************************************************************************//***********************************************//
  &((Keychord){ 1,      {{ MODKEY, XK_Return }}, zoom,           {0        } } ), // Moves The Foucsed Window to The Master Stack    //
  //******************************************************************************//*************************************************//
  &((Keychord){ 1,           {{ MODKEY, XK_g }}, togglefloating, {0        } } ), // Makes the Window Float                          //
  //******************************************************************************//*************************************************//
  &((Keychord){ 1, {{ MODKEY|ShiftMask, XK_0 }}, tag,            {.ui = ~0 } } ), // Makes The Window Appers in all Tags             //
  //******************************************************************************//*************************************************//

  //**********************************************************************************************************************************//
  // Layout                                                                                                             | _ | + | x | //
  //**********************************************************************************//**********************************************//
  &((Keychord){ 1,           {{ MODKEY, XK_i }}, incnmaster, {.i = +1          } } ), // Increase | The Windows of The Master Stack   //
  &((Keychord){ 1,           {{ MODKEY, XK_u }}, incnmaster, {.i = -1          } } ), // Decrease | The Windows of The Master Stack   //
  //**********************************************************************************//**********************************************//
  &((Keychord){ 1, {{ MODKEY|ShiftMask, XK_a }}, setlayout,  {.v = &layouts[0] } } ), // Changes The Layout to | Tiled                //
  &((Keychord){ 1, {{ MODKEY|ShiftMask, XK_s }}, setlayout,  {.v = &layouts[1] } } ), // Changes The Layout to | Floating             //
  &((Keychord){ 1, {{ MODKEY|ShiftMask, XK_d }}, setlayout,  {.v = &layouts[2] } } ), // Changes The Layout to | Columns              //
  &((Keychord){ 1, {{ MODKEY|ShiftMask, XK_f }}, setlayout,  {.v = &layouts[3] } } ), // Changes The Layout to | Monocle (Fullscreen) //
  //**********************************************************************************//**********************************************//
  &((Keychord){ 1,           {{ MODKEY, XK_l }}, setmfact,   {.f = +0.05       } } ), // Increase | The Size of The Master Stack      //
  &((Keychord){ 1,           {{ MODKEY, XK_h }}, setmfact,   {.f = -0.05       } } ), // Decrease | The Size of The Master Stack      //
  //**********************************************************************************//**********************************************//
  &((Keychord){ 1,           {{ MODKEY, XK_v }}, togglebar,  {0                } } ), // Toggles The Top Bar                          //
  //**********************************************************************************//**********************************************//
  &((Keychord){ 1,       {{ MODKEY, XK_minus }}, setgaps,    {.i = -1          } } ), // Decrease | The Gap Size Between Windows      //
  &((Keychord){ 1,       {{ MODKEY, XK_equal }}, setgaps,    {.i = +1          } } ), // Increase | The Gap Size Between Windows      //
  //&((Keychord){ 1,       {{ MODKEY, XK_plus  }}, setgaps,    {.v = gappx       } } ), // Reset    | The Gap Size Between Windows      //
  //**********************************************************************************//**********************************************//
 
  //*******************************************************************************************************************//
  // Hotkeys                                                                                             | _ | + | x | //
  //************************************************************************************//*****************************//
  &((Keychord){ 1,           { { MODKEY, XK_space }}, spawn,    {.v = xkbmap     } } ), // Changes The Keyboard Layout //
  //************************************************************************************//*****************************//
  &((Keychord){ 1,        { { ShiftMask, XK_Print }}, spawn,    {.v = prtselcmd  } } ), // Screenshot | Selection      //
  &((Keychord){ 1,           { { MODKEY, XK_Print }}, spawn,    {.v = prtfscmd   } } ), // Screenshot | Fullscreen     //
  //************************************************************************************//*****************************//
  &((Keychord){ 1, { { 0, XF86XK_AudioRaiseVolume }}, spawn,     {.v = volupcmd  } } ), // Volume | Up                 //
  &((Keychord){ 1, { { 0, XF86XK_AudioLowerVolume }}, spawn,    {.v = voldowncmd } } ), // Volume | Down               //
  &((Keychord){ 1, { { 0,        XF86XK_AudioMute }}, spawn,       {.v = volmcmd } } ), // Volume | Mute               //
  //************************************************************************************//*****************************//
  &((Keychord){ 1,   {{ 0, XF86XK_MonBrightnessUp }}, spawn,   {.v = brightupcmd } } ), // Brightness | Up             //
  &((Keychord){ 1, {{ 0, XF86XK_MonBrightnessDown }}, spawn, {.v = brightdowncmd } } ), // Brightness | Down           //
  //************************************************************************************//*****************************//

  //***************************************************************************************************************//
  // Tags                                                                                            | _ | + | x | //
  //***********************************************************************//**************************************//
  &((Keychord){ 1, { { MODKEY, XK_a } },  shiftview,      {.i = -1  } } ), // Shift the View to the | Previous Tag //
  &((Keychord){ 1, { { MODKEY, XK_s } },  shiftview,      {.i = +1  } } ), // Shift the View to the | Next Tag     //
  &((Keychord){ 1, { { MODKEY, XK_0 } },  view,           {.ui = ~0 } } ), // Shows All Tags                       //
  //***********************************************************************//**************************************//
  TAGKEYS(                         XK_1,                                0) // Switch To Tag | 1                    //
  TAGKEYS(                         XK_2,                                1) // Switch To Tag | 2                    //
  TAGKEYS(                         XK_3,                                2) // Switch To Tag | 3                    //
  TAGKEYS(                         XK_4,                                3) // Switch To Tag | 4                    //
  TAGKEYS(                         XK_5,                                4) // Switch To Tag | 5                    //
  TAGKEYS(                         XK_6,                                5) // Switch To Tag | 6                    //
  TAGKEYS(                         XK_7,                                6) // Switch To Tag | 7                    //
  TAGKEYS(                         XK_8,                                7) // Switch To Tag | 8                    //
  TAGKEYS(                         XK_9,                                8) // Switch To Tag | 9                    //
  //***********************************************************************//**************************************//
 
  //********************************************************************************************************//
  // Scripts                                                                                                //
  //************************************************************************************//**************//
  &((Keychord){ 1,    { { MODKEY|ShiftMask, XK_q } }, spawn, {.v = byecmd        } } ), // Bye :D       //
  //************************************************************************************//**************//
  &((Keychord){ 2, { { MODKEY, XK_d }, { 0, XK_b } }, spawn, {.v = webmarkcmd    } } ), // Webmark      //
  &((Keychord){ 2, { { MODKEY, XK_d }, { 0, XK_w } }, spawn, {.v = wallchangecmd } } ), // WallChange   //
  &((Keychord){ 2, { { MODKEY, XK_d }, { 0, XK_a } }, spawn, {.v = ambientercmd  } } ), // Ambienter    //
  //************************************************************************************//**************//
  &((Keychord){ 1,         { { MODKEY, XK_period } }, spawn, {.v = emojicmd      } } ), // Emoji Menu   //
  &((Keychord){ 1,         { { MODKEY, XK_comma  } }, spawn, {.v = kamojicmd     } } ), // Kamoji Menu  //
  &((Keychord){ 1,              { { MODKEY, XK_m } }, spawn, {.v = keepasscmd    } } ), // KeePass Menu //
  //************************************************************************************//**************//

  &((Keychord){ 1, {{ MODKEY, XK_F5 }},     xrdb,           {.v = NULL } }),
};

static const Button buttons[] = { // Mouse Bindings
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0            } },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0            } },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0            } },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0            } },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0            } },
  { ClkTagBar,            0,              Button1,        view,           {0            } },
  { ClkTagBar,            0,              Button3,        toggleview,     {0            } },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0            } },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0            } },
};

