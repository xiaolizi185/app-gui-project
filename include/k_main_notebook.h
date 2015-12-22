/*
 * k_main_notebook.h
 *
 *  Created on: 2015年10月14日
 *      Author: root
 */

#ifndef INCLUDE_K_MAIN_NOTEBOOK_H_
#define INCLUDE_K_MAIN_NOTEBOOK_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/.
 */

typedef struct _KMainNoteBook KMainNoteBook;
typedef struct _KMainNoteBookClass KMainNoteBookClass;

#define G_TYPE_MAIN_NOTEBOOK                         (main_notebook_get_type ())
#define MAIN_NOTEBOOK(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_MAIN_NOTEBOOK, KMainNoteBook))
#define IS_MAIN_NOTEBOOK(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_MAIN_NOTEBOOK))
#define MAIN_NOTEBOOK_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_MAIN_NOTEBOOK, KMainNoteBookClass))
#define IS_MAIN_NOTEBOOK_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_MAIN_NOTEBOOK))
#define MAIN_NOTEBOOK_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_MAIN_NOTEBOOK, KMainNoteBookClass))

struct _KMainNoteBook {
	GObject object;
	GObject *wrap_notebook;
	GtkContainer *container;
};

struct _KMainNoteBookClass {
	GObjectClass parent_class;
};

GType main_notebook_get_type(void);
void main_notebook_class_init(KMainNoteBookClass *klass);
void main_notebook_init(KMainNoteBook *main_notebook);
void main_notebook_dispose(GObject *object);

KMainNoteBook *k_main_notebook_new(GtkContainer *container);

gboolean main_notebook_set_host(KMainNoteBook *main_notebook, const gchar *ip, const gchar *port,GtkTreeView *treeview);

gboolean main_notebook_set_cluster(KMainNoteBook *main_notebook, const gchar *ip, const gchar *port);

gboolean main_notebook_set_home(KMainNoteBook *main_notebook,GtkTreeView *treeview);

G_END_DECLS

#endif /* INCLUDE_K_MAIN_NOTEBOOK_H_ */
