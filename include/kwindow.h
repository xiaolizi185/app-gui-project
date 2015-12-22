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

#ifndef __K_WINDOW_H__
#define __K_WINDOW_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _KWindow KWindow;
typedef struct _KWindowClass KWindowClass;

#define G_TYPE_K_WINDOW                         (k_window_get_type ())
#define K_WINDOW(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_K_WINDOW, KWindow))
#define IS_K_WINDOW(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_K_WINDOW))
#define K_WINDOW_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_K_WINDOW, KWindowClass))
#define IS_K_WINDOW_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_K_WINDOW))
#define K_WINDOW_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_K_WINDOW, KWindowClass))

struct _KWindow {
	GObject object;
	GtkBuilder *builder;
	GtkWindow* window;
	GtkBox* menubarview;
	GtkMenuBar* menubar;
	GtkBox* toolbarview;
	GtkToolbar* toolbar;
	GtkPaned* paned;
	GtkTreeView* tree;
	GtkStatusbar* statusbar;
	GtkPaned* task_paned;
};

struct _KWindowClass {
	GObjectClass parent_class;
};

GType k_window_get_type(void);
void k_window_class_init(KWindowClass *klass);
void k_window_init(KWindow *k_window);
void k_window_dispose(GObject *object);

KWindow* k_window_new();

void k_window_add_menubar(KWindow *kwindow, GtkWidget *menubar);

void k_window_add_toolbar(KWindow *kwindow, GtkWidget *toolbar);

void k_window_show(KWindow *kwindow);

void k_window_signal_quit(KWindow *kwindow);

void k_window_add_treeview(KWindow *kwindow, GtkTreeView *treeview,GtkWidget *window);
void k_window_add_task_treeview(KWindow *kwindow, GtkWidget *task_tree);
G_END_DECLS

#endif /* __K_WINDOW_H__ */
