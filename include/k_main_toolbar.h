/*
 * k_main_toolbar.h
 *
 *  Created on: 2015年10月10日
 *      Author: root
 */

#ifndef INCLUDE_K_MAIN_TOOLBAR_H_
#define INCLUDE_K_MAIN_TOOLBAR_H_

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

typedef struct _KMainToolbar KMainToolbar;
typedef struct _KMainToolbarClass KMainToolbarClass;

#define G_TYPE_MAIN_TOOL_BAR                         (main_tool_bar_get_type ())
#define MAIN_TOOL_BAR(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_MAIN_TOOL_BAR, KMainToolbar))
#define IS_MAIN_TOOL_BAR(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_MAIN_TOOL_BAR))
#define MAIN_TOOL_BAR_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_MAIN_TOOL_BAR, KMainToolbarClass))
#define IS_MAIN_TOOL_BAR_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_MAIN_TOOL_BAR))
#define MAIN_TOOL_BAR_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_MAIN_TOOL_BAR, KMainToolbarClass))

struct _KMainToolbar {
	GObject object;
	GtkBuilder *builder;
	GtkToolbar *toolbar;
	GtkToolButton *import;
	GtkToolButton *export;
	GtkToolButton *add_server;
	GtkToolButton *create_cluster;
	GtkToolButton *restart_host;
	GtkToolButton *stop_host;
	GtkToolButton *pause_host;
};

struct _KMainToolbarClass {
	GObjectClass parent_class;
};

GType main_tool_bar_get_type(void);
void main_tool_bar_class_init(KMainToolbarClass *klass);
void main_tool_bar_init(KMainToolbar *main_tool_bar);
void main_tool_bar_dispose(GObject *object);

KMainToolbar *k_main_tool_bar_new(KMainTreeView *kmain_treeview);

#endif /* INCLUDE_K_MAIN_TOOLBAR_H_ */
