#include <gtk/gtk.h>

//#include "k_main_menu_bar.h"
#include "kwindow.h"
//#include "view-model.h"
//#include "khost_notebook.h"
//#include "khome.h"
//#include "kcluster_notebook.h"
//#include "popup-menu.h"
//#include "common.h"
//#include "k_main_toolbar.h"
//#include "k_main_treeview.h"
//#include "k_main_notebook.h"
//#include "k_task_treeview.h"

//void init_logging_handler() {
//	open_log_file();
//	/*g_log_set_handler("kreactor", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_host_general", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_host_memory", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_host_networking", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_host_nic", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_host_storage", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_main_treeview", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_host_service", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("khost_notebook", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_cluster_general", G_LOG_LEVEL_MASK, log2console, NULL);
//	 g_log_set_handler("k_cluster_networking", G_LOG_LEVEL_MASK, log2console,
//	 NULL);*/
//	g_log_set_handler("kreactor", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_host_general", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_host_memory", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_host_networking", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_host_nic", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_host_storage", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_main_treeview", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_host_service", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("khost_notebook", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_cluster_general", G_LOG_LEVEL_MASK, log2file, NULL);
//	g_log_set_handler("k_cluster_networking", G_LOG_LEVEL_MASK, log2file,
//	NULL);
//}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

//	init_logging_handler();

	KWindow* kwindow = k_window_new();

//	KMainNoteBook *k_main_notebook = k_main_notebook_new(
//			GTK_CONTAINER(kwindow->paned));
//
//	KMainTreeView *kmain_treeview = k_main_treeview_new(k_main_notebook);
//	k_window_add_treeview(kwindow, kmain_treeview->treeview,GTK_WIDGET(kmain_treeview->window));
//
//	KMainMenuBar *kmain_menu_bar = k_main_menu_bar_new(kmain_treeview);
//	k_window_add_menubar(kwindow, GTK_WIDGET(kmain_menu_bar->menubar));
//
//	KMainToolbar *k_main_toolbar = k_main_tool_bar_new(kmain_treeview);
//	k_window_add_toolbar(kwindow, GTK_WIDGET(k_main_toolbar->toolbar));

//	k_task_treeview = k_task_treeview_new();
//	k_window_add_task_treeview(kwindow, GTK_WIDGET(k_task_treeview->frame));

	k_window_show(kwindow);

	k_window_signal_quit(kwindow);

	gtk_main();

//	g_object_unref(k_main_toolbar);
//	g_object_unref(kmain_menu_bar);
//	g_object_unref(k_main_notebook);
//	g_object_unref(kwindow);

	return 0;
}
