#include <stdio.h>
#include <gtk/gtk.h>
#include "kwindow.h"
#include "k_module_load.h"
#include "k_main_builder.h"

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	Kmain_builder* k_main_builer = k_main_builder_new();
	KWindow* kwindow = k_window_new(k_main_builer);
	load_main(kwindow);
	load_menu_bar();
	load_tools_bar();
	load_status_bar();

	/*GtkWidget *palette, *group;
	GtkToolItem *item;

	palette = gtk_tool_palette_new();
	group = gtk_tool_item_group_new(("application"));
	gtk_container_add(GTK_CONTAINER(palette), group);

	item = gtk_tool_button_new(NULL, ("_Open"));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(item), "document-open");
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group), item, -1);

	item = gtk_tool_button_new(NULL, ("_Open"));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(item), "document-open");
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group), item, -1);
	gtk_container_set_border_width(GTK_CONTAINER(palette), 6);
	gtk_paned_add1(kwindow->paned, GTK_WIDGET(palette));*/

	//listbox = gtk_list_box_new();

	gtk_widget_show_all(GTK_WIDGET(kwindow->window));
	k_window_signal_quit(kwindow);
	gtk_main();
	g_object_unref(kwindow);
	return 1;
}
