void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}
void
focusnthmonx(const Arg *arg)
{
	focusnthmon(&((Arg) { .i = arg->i }));
}
void
tagnthmonx(const Arg *arg)
{
	tagnthmon(&((Arg) { .i = arg->i }));
}
void
togglescratchx(const Arg *arg)
{
	togglescratch(&((Arg) { .ui = arg->i }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           		function */
	{ "focusstack",     		focusstack },
	{ "shiftview",     			shiftview },
	{ "movestack",     			movestack },
	{ "setmfact",       		setmfact },
	{ "setcfact",       		setcfact },
	{ "togglebar",      		togglebar },
	{ "incnmaster",     		incnmaster },
	{ "togglefloating", 		togglefloating },
	{ "togglefullscr", 			togglefullscr },
	{ "focusmon",       		focusmon },
	{ "tagmon",         		tagmon },
	{ "zoom",           		zoom },
	{ "view",           		view },
	{ "viewall",        		viewall },
	{ "viewex",         		viewex },
	{ "toggleview",     		view },
	{ "toggleviewex",   		toggleviewex },
	{ "tag",            		tag },
	{ "tagall",         		tagall },
	{ "tagex",          		tagex },
	{ "toggletag",      		tag },
	{ "toggletagex",    		toggletagex },
	{ "killclient",     		killclient },
	{ "quit",           		quit },
	{ "setlayout",      		setlayout },
	{ "setlayoutex",    		setlayoutex },
	{ "focusnthmonx",    		focusnthmonx},
	{ "togglescratchx", 		togglescratchx},
	{ "cyclelayout", 			cyclelayout},
	{ "togglesticky", 			togglesticky},
	{ "incrivgaps", 			incrivgaps},
	{ "incrihgaps", 			incrihgaps},
	{ "incrovgaps", 			incrovgaps},
	{ "incrohgaps", 			incrohgaps},
	{ "incrogaps", 				incrogaps},
	{ "incrigaps", 				incrigaps},
	{ "incrgaps", 				incrgaps},
	{ "defaultgaps", 			defaultgaps},
	{ "togglegaps", 			togglegaps},
	{ "tagnthmonx", 			tagnthmonx},
};
