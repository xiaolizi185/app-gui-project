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

#include "kwindow.h"
GType k_window_get_type(void) {
	static GType g_type = 0;

	if (!g_type) {
		const GTypeInfo type_info = { sizeof(KWindowClass),
		NULL,
		NULL, (GClassInitFunc) k_window_class_init,
		NULL,
		NULL, sizeof(KWindow), 0, (GInstanceInitFunc) k_window_init,
		NULL };

		g_type = g_type_register_static(G_TYPE_OBJECT, "KWindow", &type_info,
				0);
	}
	return g_type;
}

void k_window_class_init(KWindowClass *klass) {
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

	gobject_class->dispose = k_window_dispose;
}

void k_window_init(KWindow *k_window) {
	k_window->menubar = NULL;
	k_window->menubarview = NULL;
	k_window->paned = NULL;
	k_window->statusbar = NULL;
	k_window->toolbar = NULL;
	k_window->toolbarview = NULL;
	k_window->tree = NULL;
	k_window->window = NULL;
}

void k_window_dispose(GObject *object) {
	KWindow *k_window = NULL;
	k_window = K_WINDOW(object);

	if (k_window->menubar) {
		g_object_unref(k_window->menubar);
	}

	if (k_window->toolbar) {
		g_object_unref(k_window->toolbar);
	}

	if (k_window->tree) {
		g_object_unref(k_window->tree);
	}

	if (k_window->builder) {
		g_object_unref(k_window->builder);
	}

	GObjectClass *parent_class = g_type_class_ref(G_TYPE_OBJECT);

	G_OBJECT_CLASS (parent_class)->dispose(object);
}

KWindow* k_window_new(Kmain_builder* k_main_builer) {
	KWindow *k_window = g_object_new(G_TYPE_K_WINDOW, NULL);
	GtkBuilder* builder = gtk_builder_new_from_file("./glade/k_window.glade");
	k_window->builder = builder;
	k_window->window = GTK_WINDOW(
			gtk_builder_get_object(k_window->builder, "window1"));
	k_window->toolbarview = GTK_BOX(
			gtk_builder_get_object(k_window->builder, "box1"));
	k_window->menubarview = GTK_BOX(
			gtk_builder_get_object(k_window->builder, "box3"));
	k_window->paned = GTK_PANED(
			gtk_builder_get_object(k_window->builder, "paned1"));
	k_window->statusbar = GTK_STATUSBAR(
			gtk_builder_get_object(k_window->builder, "statusbar1"));
	k_window->task_paned = GTK_PANED(
			gtk_builder_get_object(k_window->builder, "paned2"));
	k_window->sw1 = GTK_SCROLLED_WINDOW(
				gtk_builder_get_object(k_window->builder, "scrolledwindow2"));

	k_main_builer->mainwindow_builder = builder;
	return (KWindow*) k_window;
}

void k_window_show(KWindow *kwindow) {
	gtk_widget_show_all(GTK_WIDGET(kwindow->window));
}

void k_window_add_menubar(KWindow *kwindow, GtkWidget *menubar) {
	g_object_ref(menubar);
	kwindow->menubar = GTK_MENU_BAR(menubar);
	gtk_box_pack_start(GTK_BOX(kwindow->menubarview), GTK_WIDGET(menubar),
			FALSE, TRUE, 1);
}

void k_window_add_toolbar(KWindow *kwindow, GtkWidget *toolbar) {
	g_object_ref(toolbar);
	kwindow->toolbar = GTK_TOOLBAR(toolbar);
	gtk_box_pack_start(GTK_BOX(kwindow->toolbarview), GTK_WIDGET(toolbar),
			FALSE, TRUE, 1);
}

void k_window_add_treeview(KWindow *kwindow, GtkTreeView *treeview,GtkWidget *window) {
	g_object_ref(treeview);
	kwindow->tree = GTK_TREE_VIEW(treeview);
	gtk_paned_add1(kwindow->paned, GTK_WIDGET(window));
}

void k_window_add_task_treeview(KWindow *kwindow, GtkWidget *task_tree) {
	g_object_ref(task_tree);
	gtk_paned_add1(GTK_PANED(kwindow->task_paned),
			GTK_WIDGET(task_tree));
}

void k_window_signal_quit(KWindow *kwindow) {
	//close_log_file();
	g_signal_connect_swapped(G_OBJECT(kwindow->window), "destroy",
			G_CALLBACK(gtk_main_quit), NULL);
}
