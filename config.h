/* See LICENSE file for copyright and license details. */
/* Theme implementation for Stuart (Just macros lol), just uncomment the theme you want to use */

/* Theme Changer Prototype */
#define GOLDEN_GREEN
// #define STUART_DARK
// #define GOLDEN_GREEN

#ifdef GOLDEN_GREEN
static const char col_gray1[]       = "#1E1E1E";
static const char col_gray2[]       = "#2A2A2A";
static const char col_gray3[]       = "#AAD1FF";
static const char col_gray4[]       = "#FFD700";
static const char col_color[]       = "#4C9E7A";
#endif

#ifdef STUART_LIGHT
static const char col_gray1[]       = "#f1f1f1";
static const char col_gray2[]       = "#2A2A2A";
static const char col_gray3[]       = "#1f1f1f";
static const char col_gray4[]       = "#f1f1f1";
static const char col_color[]       = "#1f1f1f";
#endif

#ifdef STUART_DARK // XD
static const char col_gray1[]       = "#1f1f1f";
static const char col_gray2[]       = "#2A2A2A";
static const char col_gray3[]       = "#f1f1f1";
static const char col_gray4[]       = "#1f1f1f";
static const char col_color[]       = "#f1f1f1";
#endif

/* Vanitygaps Patch */

static const unsigned int gappih    = 10; /* horiz inner gap between windows */
static const unsigned int gappiv    = 10; /* vert inner gap between windows */
static const unsigned int gappoh    = 10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10; /* vert outer gap between windows and screen edge */

/* Barpadding Patch */

static const int vertpad 	    = 10; /* vertical padding */
static const int sidepad	    = 10; /* horizontal padding */

/* Vanilla appearance */
static const unsigned int borderpx  = 2;       /* border pixel of windows */
static const unsigned int snap      = 0;        /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=10" };
static const char dmenufont[]       = "monospace:size=10";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_color, col_color },
};

/* tagging */
static const char *tags[] = { "1", "2" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance       title       tags mask     isfloating   monitor */
	{ "Gimp",        NULL,       NULL,       0,            0,           -1 },
	{ "pavucontrol", NULL, 	     NULL,	     0,            1,           -1 },
};

/* layout(s) */
static const float mfact     	= 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     	= 1;    /* number of clients in master area */
static const int resizehints 	= 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " ",      tile },    /* first entry is default */
	{ " ",      NULL },    /* no layout function means floating behavior */
	{ " ",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_color, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "xfce4-terminal", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* This hotkeys are from Vanitygaps Patch */
	/* Commented because I need to remap...
	{ MODKEY|Mod4Mask,				XK_h,	   incrgaps,	   { .i = +1 } },
	{ MODKEY|Mod4Mask,				XK_l,	   incrgaps,       { .i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_h,	   incrogaps,      { .i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_l,      incrogaps,      { .i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      { .i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      { .i = -1 } },
	{ MODKEY|Mod4Mask,				XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,	XK_0,	   defaultgaps,    {0} },
	{ MODKEY,						XK_y,      incrihgaps,     { .i = +1 } },
	{ MODKEY,						XK_o,	   incrihgaps,     { .i = -1 } },
	{ MODKEY|ControlMask,			XK_y, 	   incrivgaps,     { .i = +1 } },
	{ MODKEY|ControlMask,			XK_o,	   incrivgaps,	   { .i = -1 } },
	{ MODKEY|Mod4Mask,				XK_y,	   incrohgaps,     { .i = +1 } },
	{ MODKEY|Mod4Mask,				XK_o,	   incrohgaps,	   { .i = -1 } },
	{ MODKEY|ShiftMask,				XK_y,      incrovgaps,     { .i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     { .i = -1 } },
	*/
	{ MODKEY,						XK_F1,	   spawn,	       SHCMD("alacritty -e ~/.config/super-dwm/scripts/superhelp.sh") },
	{ MODKEY,						XK_F11,    spawn,	       SHCMD("brightnessctl set 5%-") },
	{ MODKEY,						XK_F12,    spawn,          SHCMD("brightnessctl set +5%") },
	{ MODKEY,           			XK_p,      spawn,          SHCMD("xfce4-screenshooter") },
	{ MODKEY,						XK_e,	   spawn,	   	   SHCMD("thunar") },
	{ MODKEY,						XK_v,	   spawn,	   	   SHCMD("pavucontrol") },
	{ MODKEY,						XK_d,      spawn,	   	   SHCMD("rofi -show drun -show-icons") },
	{ MODKEY,             			XK_Return, spawn,          { .v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_c, 	   zoom,           {0} }, 
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,				XK_f,	   fullscreen,     {0} }, /* Fullscreen Patch */
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask, 			XK_Escape,      spawn,	   SHCMD("pkill statusbar.sh") },
	{ MODKEY|ShiftMask,             XK_Escape,      quit,      {0} },
	
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


