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

#ifndef __K_MAIN_BUILDER_H__
#define __K_MAIN_BUILDER_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _Kmain_builder Kmain_builder;
typedef struct _KMain_builderClass KMain_builderClass;

#define G_TYPE_K_MAIN_BUILDER                         (k_main_builder_get_type ())
#define K_MAIN_BUILDER(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_K_MAIN_BUILDER, Kmain_builder))
#define IS_K_MAIN_BUILDER(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_K_MAIN_BUILDER))
#define K_MAIN_BUILDER_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_K_MAIN_BUILDER, KMain_builderClass))
#define IS_K_MAIN_BUILDER_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPEK_MAIN_BUILDER))
#define K_MAIN_BUILDER_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_K_MAIN_BUILDER, KMain_builderClass))

struct _Kmain_builder {
	GObject object;
	GtkBuilder *mainwindow_builder;
	GtkBuilder *toolbar_builder;
	GtkBuilder *menubar_builder;
	GtkBuilder *statusbar_builder;
	GtkBuilder *palette_builder;
};

struct _KMain_builderClass {
	GObjectClass parent_class;
};

GType k_main_builder_get_type(void);
void k_main_builder_class_init(KMain_builderClass *klass);
void k_main_builder_init(Kmain_builder *k_main_builder);
void k_main_builder_dispose(GObject *object);

Kmain_builder* k_main_builder_new();

G_END_DECLS

#endif /* __K_MAIN_BUILDER_H__ */
