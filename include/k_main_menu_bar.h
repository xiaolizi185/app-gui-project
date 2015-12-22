/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

#ifndef INCLUDE_K_MAIN_MENU_BAR_H_
#define INCLUDE_K_MAIN_MENU_BAR_H_

#include <gtk/gtk.h>
#include "kwindow.h"
#include "k_main_treeview.h"
G_BEGIN_DECLS

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

typedef struct _KMainMenuBar KMainMenuBar;
typedef struct _KMainMenuBarClass MainMenuBarClass;

#define G_TYPE_MAIN_MENU_BAR                         (main_menu_bar_get_type ())
#define MAIN_MENU_BAR(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_MAIN_MENU_BAR, KMainMenuBar))
#define IS_MAIN_MENU_BAR(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_MAIN_MENU_BAR))
#define MAIN_MENU_BAR_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_MAIN_MENU_BAR, MainMenuBarClass))
#define IS_MAIN_MENU_BAR_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_MAIN_MENU_BAR))
#define MAIN_MENU_BAR_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_MAIN_MENU_BAR, MainMenuBarClass))

struct _KMainMenuBar {
	GObject object;
	GtkBuilder* builder;
	GtkMenuBar* menubar;
	GtkMenuItem *exit;
	GtkMenuItem *addserver;
	GtkMenuItem *removeserver;
	GtkMenuItem *shutdown;
	GtkMenuItem *reboot;
	GtkMenuItem *addtopool;
	GtkMenuItem *newpool;
	GtkMenuItem *removepool;
	GtkMenuItem *about;
	GtkMenuItem *exportlist;
	GtkMenuItem *importlist;
};

struct _KMainMenuBarClass {
	GObjectClass parent_class;
};

GType main_menu_bar_get_type(void);
void main_menu_bar_class_init(MainMenuBarClass *klass);
void main_menu_bar_init(KMainMenuBar *main_menu_bar);
void main_menu_bar_dispose(GObject *object);

KMainMenuBar *k_main_menu_bar_new(KMainTreeView *kmain_treeview);

G_END_DECLS

#endif /* INCLUDE_K_MAIN_MENU_BAR_H_ */
