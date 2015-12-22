#ifndef INCLUDE_POPUP_CALLBACK_H_
#define INCLUDE_POPUP_CALLBACK_H_

#include "common.h"
G_BEGIN_DECLS

void callback_delete_cluster(GtkWidget *menuitem, gpointer userdata);
void callback_create_cluster(GtkWidget *menuitem, gpointer userdata);
void callback_cluster_add_host(GtkWidget *menuitem, gpointer userdata);
void callback_add_host(GtkWidget *menuitem, gpointer userdata);
void callback_reomve_host(GtkWidget *menuitem, gpointer userdata);
void callback_reomve_host_from_cluster(GtkWidget *menuitem, gpointer userdata);
void callback_shutdown_host(GtkWidget *menuitem, gpointer userdata);
void callback_reboot_host(GtkWidget *menuitem, gpointer userdata);
void callback_add_one_host_to_cluster(GtkWidget *menuitem, gpointer userdata);
void exit_app(GtkWidget *, gpointer );
void export_dialog(GtkWidget *, gpointer);
void about_dialog(GtkWidget *, gpointer);
void callback_conf_host(GtkWidget *menuitem, gpointer userdata);
void callback_stop_cluster(GtkWidget *menuitem, gpointer userdata);
void callback_start_cluster(GtkWidget *menuitem, gpointer userdata);

G_END_DECLS

#endif /* INCLUDE_POPUP_CALLBACK_H_ */
