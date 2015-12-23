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

#include "k_main_builder.h"
GType k_main_builder_get_type(void) {
	static GType g_type = 0;

	if (!g_type) {
		const GTypeInfo type_info = { sizeof(KMain_builderClass),
		NULL,
		NULL, (GClassInitFunc) k_main_builder_class_init,
		NULL,
		NULL, sizeof(Kmain_builder), 0, (GInstanceInitFunc) k_main_builder_init,
		NULL };

		g_type = g_type_register_static(G_TYPE_OBJECT, "Kmain_builder",
				&type_info, 0);
	}
	return g_type;
}

void k_main_builder_class_init(KMain_builderClass *klass) {
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;

	gobject_class->dispose = k_main_builder_dispose;
}

void k_main_builder_init(Kmain_builder *k_main_builder) {
	k_main_builder->mainwindow_builder = NULL;
	k_main_builder->menubar_builder = NULL;
	k_main_builder->palette_builder = NULL;
	k_main_builder->statusbar_builder = NULL;
	k_main_builder->toolbar_builder = NULL;
}

void k_main_builder_dispose(GObject *object) {
	Kmain_builder *k_main_builder = NULL;
	k_main_builder = K_MAIN_BUILDER(object);

	if (k_main_builder->mainwindow_builder) {
		g_object_unref(k_main_builder->mainwindow_builder);
	}
	if (k_main_builder->menubar_builder) {
		g_object_unref(k_main_builder->menubar_builder);
	}
	if (k_main_builder->palette_builder) {
		g_object_unref(k_main_builder->palette_builder);
	}
	if (k_main_builder->statusbar_builder) {
		g_object_unref(k_main_builder->statusbar_builder);
	}
	if (k_main_builder->toolbar_builder) {
		g_object_unref(k_main_builder->toolbar_builder);
	}

	GObjectClass *parent_class = g_type_class_ref(G_TYPE_OBJECT);

	G_OBJECT_CLASS (parent_class)->dispose(object);
}

Kmain_builder* k_main_builder_new() {
	Kmain_builder *k_main_builder = g_object_new(G_TYPE_K_MAIN_BUILDER, NULL);
	k_main_builder->mainwindow_builder = NULL;
	k_main_builder->menubar_builder = NULL;
	k_main_builder->palette_builder = NULL;
	k_main_builder->statusbar_builder = NULL;
	k_main_builder->toolbar_builder = NULL;
	return (Kmain_builder*) k_main_builder;
}

