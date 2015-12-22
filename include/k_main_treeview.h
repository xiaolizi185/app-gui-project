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

#ifndef INCLUDE_K_MAIN_TREEVIEW_H_
#define INCLUDE_K_MAIN_TREEVIEW_H_

#include <gtk/gtk.h>
#include "k_view_model_hash.h"
#include "kreactor.h"
#include "k_main_notebook.h"

G_BEGIN_DECLS

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */
enum {
	ICON_NAME = 0,
	NODE_NAME,
	NODE_IP,
	NODE_FLOATIP,
	NODE_TYPE,
	NODE_NFSIP,
	NODE_MASTER,
	COLUMNS
};
typedef struct _KMainTreeView KMainTreeView;
typedef struct _KMainTreeViewClass KMainTreeViewClass;

#define G_TYPE_MAIN_TREEVIEW                         (main_treeview_get_type ())
#define MAIN_TREEVIEW(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_MAIN_TREEVIEW, KMainTreeView))
#define IS_MAIN_TREEVIEW(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_MAIN_TREEVIEW))
#define MAIN_TREEVIEW_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_MAIN_TREEVIEW, KMainTreeViewClass))
#define IS_MAIN_TREEVIEW_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_MAIN_TREEVIEW))
#define MAIN_TREEVIEW_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_MAIN_TREEVIEW, KMainTreeViewClass))

struct _KMainTreeView {
	GObject object;
	GtkBuilder* builder;
	GtkTreeView *treeview;
	GtkTreeStore *treestore;
	GtkTreeSelection *treeselection;
	GMutex mutex;
	KMainNoteBook *main_notebook;
	KViewModelHash *viewmodelhash;
	GHashTable *tree_hash;
	GtkScrolledWindow *window;
	GTimeoutSystem *tree_timeout_system;
	GAsyncSystem *tree_cluster_async_system;
	GAsyncSystem *tree_host_async_system;
	GAsyncSystem *operation_async_system;
};

struct _KMainTreeViewClass {
	GObjectClass parent_class;
};

GType main_treeview_get_type(void);
void main_treeview_class_init(KMainTreeViewClass *klass);
void main_treeview_init(KMainTreeView *main_treeview);
void main_treeview_dispose(GObject *object);

KMainTreeView *k_main_treeview_new(KMainNoteBook *main_notebook);


typedef struct _KMainTreeViewGetData KMainTreeViewGetData;
struct _KMainTreeViewGetData {
	GString *ip;
	GString *float_ip;
	KMainTreeView *main_treeview;
};

G_END_DECLS

#endif /* INCLUDE_K_MAIN_TREEVIEW_H_ */
