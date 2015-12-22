#ifndef INCLUDE_DIALOG_H_
#define INCLUDE_DIALOG_H_

#include "common.h"
#include "k_list.h"
#include "k_call_rpc_function.h"
#include "k_import_export.h"
#include "k_view_model_hash.h"
#include "kreactor.h"
G_BEGIN_DECLS

typedef struct _KDeleteClusterDialog KDeleteClusterDialog;
typedef struct _KDeleteClusterDialogClass KDeleteClusterDialogClass;

#define G_TYPE_K_DELETECLUSTER                          (k_deletecluster_get_type ())
#define K_DELETECLUSTER(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_K_DELETECLUSTER, KDeleteClusterDialog))
#define IS_K_DELETECLUSTER(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_K_DELETECLUSTER))
#define K_DELETECLUSTER_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_K_DELETECLUSTER, KDeleteClusterDialogClass))
#define IS_K_DELETECLUSTER_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_K_DELETECLUSTER))
#define K_DELETECLUSTER_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_K_DELETECLUSTER, KDeleteClusterDialogClass))


struct _KDeleteClusterDialog {
	GObject object;
	GAsyncSystem *clusterdelete_async_system;
	gchar *ip;
	gchar *cluster_name;
	GtkDialog *progress_dialog;
	GtkDialog *result_dialog;
};

struct _KDeleteClusterDialogClass {
	GObjectClass parent_class;
};

GType k_deletecluster_get_type(void);
void k_deletecluster_class_init(KDeleteClusterDialogClass *klass);
void k_deletecluster_init(KDeleteClusterDialog *k_deletecluster) ;
void k_deletecluster_dispose(GObject *object);
KDeleteClusterDialog* k_deletecluster_new();
void delete_cluster_unref_call_back(gpointer data, GClosure *closure);
void delete_cluster_ref_call_back(gpointer data, GClosure *closure);

typedef struct _ex_im_port_t{
    GtkFileChooserWidget* filechoose;
    const gchar *filename;
    GtkTreeView *view;
    KViewModelHash *viewmodelhash;
}ex_im_port_t;

#define PACKAGE_VERSION "1.0.0"
GtkDialog *error_dialog_new_1();
GtkDialog *message_dialog_new(gchar *dialog_path);
GtkDialog *progress_bar_new(gchar *text);
GtkDialog *para_result_dialog_new(gchar *text);

void exit_app(GtkWidget *menuitem, gpointer userdata);
void about_dialog(GtkWidget *menuitem, gpointer parant);
void export_dosomething(GtkWidget *dialog, gint response_id, gpointer userdata);
void export_dialog(GtkWidget *menuitem, gpointer userdata);
void import_dialog(GtkWidget *menuitem, gpointer userdata);

G_END_DECLS

#endif /* INCLUDE_DIALOG_H_ */
