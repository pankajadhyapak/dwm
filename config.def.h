/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 8;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
/*   Display modes of the tab bar: never shown, always shown, shown only in */
/*   monocle mode in presence of several windows.                           */
/*   Modes after showtab_nmodes are disabled                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab            = showtab_auto; /* Default tab bar show mode */
static const Bool toptab            = False;    /* False means bottom tab bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=11","JoyPixels:pixelsize=10:antialias=true:autohint=true"};
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=11";
static char normbgcolor[]           = "#1E1E2E";
static char normbordercolor[]       = "#1E1E2E";
static char normfgcolor[]           = "#D9E0EE";
static char selfgcolor[]            = "#1E1E2E";
static char selbordercolor[]        = "#96CDFB";
static char selbgcolor[]            = "#96CDFB";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
 };

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "sporgmode", "-g", "120x34", "-e", "newScratchpad", NULL };
const char *spcmd2[] = {"st", "-n", "spranger", "-g", "120x34", "-e", "ranger", NULL };
const char *spcmd3[] = {"st", "-n", "spterminal", "-g", "120x34", NULL};
const char *spcmd4[] = {"sleek", NULL};
static Sp scratchpads[] = {
	/* name          	cmd  */
	{"sporgmode",  	spcmd1},
	{"spranger",    spcmd2},
	{"spterminal",  spcmd3},
	{"ticktick",	spcmd4},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* default layout per tags */
/* The first element is for all-tag view, following i-th element corresponds to */
/* tags[i]. Layout is referred using the layouts array index.*/
static int def_layouts[1 + LENGTH(tags)]  = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      			instance    	title       		tags mask     isfloating   isterminal	noswallow	monitor */
	{ "kitty",				"kittymain",  	NULL,       		1 << 0,			0,          	1,			0,		-1 },
	{ "Google-chrome",		NULL,       	NULL,       		1 << 1,       	0,          	0,			0,		-1 },
	{ "Code",				NULL,       	NULL,       		1 << 2,       	0,          	0,			0,		-1 },
	{ "jetbrains-goland",	NULL,       	NULL,       		1 << 3,       	0,          	0,			0, 		-1 },
	{ "jetbrains-phpstorm",	NULL,       	NULL,       		1 << 3,       	0,          	0,			0, 		-1 },
	{ "Mysql-workbench-bin",NULL,       	NULL,       		1 << 4,       	0,          	0,			0, 		-1 },
	{ "TablePlus",			NULL,       	NULL,       		1 << 4,       	0,          	0,			0, 		-1 },
	{ "Slack",  			NULL,       	NULL,       		1 << 6,       	0,          	0,			0,  	1 },
	{ "GitHub Desktop",		NULL,       	NULL,       		1 << 7,       	0,         		0,			0,   	1 },
	{ "Mailspring",  		NULL,       	NULL,       		1 << 8,       	0,         		0,			0,   	1 },
	{ "kitty",     			NULL,    		NULL,       		0,         		0,          	1,			0,		-1 },
	{ NULL,     			NULL,    		"Event Tester",  	0,         		0,          	0,			1,		-1 },

	// Floating windows
	{ "*:floating",  		NULL,       	NULL,      			0,       		1,           	0,			0, 		-1 },
	{ "*:pop-up",  			NULL,       	NULL,      			0,       		1,           	0,			0, 		-1 },
	{ "Thunar",  			NULL,       	NULL,      			0,       		1,          	0,			0,  	-1 },
	{ "Lxappearance",  		NULL,       	NULL,      			0,       		1,          	0,			0,  	-1 },
	{ "Arandr",  			NULL,       	NULL,      			0,       		1,           	0,			0, 		-1 },
	{ "Pavucontrol",  		NULL,       	NULL,      			0,       		1,          	0,			0,  	-1 },
	{ "Gnome-disks",  		NULL,       	NULL,      			0,       		1,          	0,			0,  	-1 },
	{ "Gnome-calculator",  	NULL,       	NULL,      			0,       		1,          	0,			0,  	-1 },
	{ "mpv",  				NULL,       	NULL,      			0,       		1,         		0,			0,   	-1 },
	{ "Nsxiv",  			NULL,       	NULL,      			0,       		1,        		0,			0,    	-1 },

	/* class      			instance    	title       		tags mask  	isfloating   isterminal	noswallow	monitor */
	{ NULL,		  			"sporgmode",	NULL,				SPTAG(0),		1,				1,		1,	 			-1 },
	{ NULL,		  			"spranger",		NULL,				SPTAG(1),		1,				1,		1,	 			-1 },
	{ NULL,		  			"spterminal",	NULL,				SPTAG(2),		1,				1,		1,	 			-1 },
	{"ticktick",			NULL,			NULL,				SPTAG(3),		1,				0,		1,	 			-1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#define STATUSBAR "dwmblocks"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */


	{ "[D]",	deck },			/* Master on left, slaves in monocle-like mode on right */
	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },

	// { "[@]",	spiral },		/* Fibonacci spiral */
	// { "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	// Other available layouts
	// { "[@]",      	spiral },
	// { "===",      	bstackhoriz },
	// { "HHH",      	grid },
	// { "###",      	nrowgrid },
	// { "---",      	horizgrid },
	// { ":::",      	gaplessgrid },
	// { ">M>",      	centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_w,      tabmode,        {-1} },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        spawn,   		SHCMD("powermenu") },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

#include "dwmc.c"
