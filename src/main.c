#include <stdio.h>
#include <gtk/gtk.h>
#include "kwindow.h"
#include "k_module_load.h"
#include "k_main_builder.h"

/*static void passive_canvas_drag_data_received(GtkWidget *widget,
		GdkDragContext *context, gint x, gint y, GtkSelectionData *selection,
		guint info, guint time, gpointer data) {

	g_print("palette drag data receiced 111111\n");
	GtkWidget *palette = gtk_drag_get_source_widget(context);
	CanvasItem *canvas_item = NULL;
	GtkWidget *tool_item = NULL;

	while (palette && !GTK_IS_TOOL_PALETTE(palette)) {
		g_print("cccccccccccccccccc\n");
		palette = gtk_widget_get_parent(palette);
	}

	if (palette)
		tool_item = gtk_tool_palette_get_drag_item(GTK_TOOL_PALETTE(palette),
				selection);

	g_assert(NULL == drop_item);



	if (GTK_IS_TOOL_ITEM(tool_item)) {
		canvas_item = canvas_item_new(widget, GTK_TOOL_BUTTON(tool_item), x, y);
	}

	if (GTK_IS_LIST_BOX(widget)) {
		gchar *button_name;
		button_name = gtk_tool_button_get_label(GTK_TOOL_BUTTON(tool_item));
		g_print("widget is list box\n");
		GtkBuilder* builder = gtk_builder_new_from_file(
				"./glade/listbox.glade");
		GtkLabel *label = GTK_LABEL(
				gtk_builder_get_object(builder, "source_name"));
		gtk_label_set_text(label, button_name);
		GtkGrid *gg = GTK_GRID(gtk_builder_get_object(builder, "grid1"));
		gtk_list_box_prepend(widget, gg);

		gtk_widget_show_all(widget);
	}

	if (canvas_item) {
		canvas_items = g_list_append(canvas_items, canvas_item);
		gtk_widget_queue_draw(widget);
	}
}
*/
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	Kmain_builder* k_main_builer = k_main_builder_new();
	KWindow* kwindow = k_window_new(k_main_builer);
	load_main(kwindow);
	/*load_menu_bar();
	load_tools_bar();
	load_status_bar();*/



/*	GtkWidget *group, *new_widget;
	GtkToolItem *item;
	GtkWidget *group1;
	GtkBuilder *builder1;
	builder1 = gtk_builder_new_from_file("./glade/k_palette.glade");

	new_widget = GTK_WIDGET(gtk_builder_get_object(builder1, "tool_palette"));
	group = gtk_tool_item_group_new(("application"));
	gtk_container_add(GTK_CONTAINER(new_widget), group);

	item = gtk_tool_button_new(NULL, ("php"));
	gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(item), "document-open");
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group), item, -1);
	item = gtk_tool_button_new(NULL, ("tomcat"));
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group), item, -1);
	item = gtk_tool_button_new(NULL, ("java"));
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group), item, -1);
	item = gtk_tool_button_new(NULL, ("mysql"));
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group), item, -1);
	group1 = gtk_tool_item_group_new(("node"));
	gtk_container_add(GTK_CONTAINER(new_widget), group1);
	item = gtk_tool_button_new(NULL, ("sgvcs11"));
	gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group1), item, -1);
	gtk_container_set_border_width(GTK_CONTAINER(new_widget), 6);

	gtk_container_add(GTK_CONTAINER(kwindow->sw1), GTK_WIDGET(new_widget));

	GtkWidget *listbox, *scrolled;
	listbox = gtk_list_box_new();
	GtkBuilder* builder = gtk_builder_new_from_file("./glade/listbox.glade");

	GtkGrid *gg = GTK_GRID(gtk_builder_get_object(builder, "grid1"));
	gtk_list_box_prepend(listbox, gg);
	builder = gtk_builder_new_from_file("./glade/listbox.glade");
	GtkGrid *gg1 = GTK_GRID(gtk_builder_get_object(builder, "grid1"));
	gtk_list_box_prepend(listbox, gg1);
	builder = gtk_builder_new_from_file("./glade/listbox.glade");
	GtkGrid *gg2 = GTK_GRID(gtk_builder_get_object(builder, "grid1"));
	gtk_list_box_prepend(listbox, gg2);
	builder = gtk_builder_new_from_file("./glade/listbox.glade");
	GtkGrid *gg3 = GTK_GRID(gtk_builder_get_object(builder, "grid1"));
	gtk_list_box_prepend(listbox, gg3);

	builder = gtk_builder_new_from_file("./glade/listbox.glade");
	GtkGrid *gg4 = GTK_GRID(gtk_builder_get_object(builder, "grid1"));

	GtkWidget *test = gtk_list_box_row_new();
	gtk_container_add(GTK_CONTAINER(test), gg4);
	gtk_list_box_prepend(listbox, test);

	gtk_container_remove(GTK_CONTAINER(listbox), GTK_WIDGET(test));
	GtkLabel *label = GTK_LABEL(gtk_builder_get_object(builder, "source_name"));
	GtkButton *expand_button = GTK_BUTTON(
			gtk_builder_get_object(builder, "expand_button"));
	gtk_label_set_text(label, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	gtk_widget_set_sensitive(GTK_WIDGET(expand_button), FALSE);

	scrolled = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(scrolled), listbox);


	gtk_paned_add2(kwindow->paned, GTK_WIDGET(scrolled));*/
	//gtk_container_remove(GTK_CONTAINER(kwindow->paned), GTK_WIDGET(scrolled));

	//g_signal_connect(new_widget, "drag-data-received",
	//	G_CALLBACK (palette_drag_data_received), NULL);

	//gtk_tool_palette_add_drag_dest(GTK_TOOL_PALETTE(new_widget), new_widget,
	//		GTK_DEST_DEFAULT_ALL,
	//		GTK_TOOL_PALETTE_DRAG_ITEMS | GTK_TOOL_PALETTE_DRAG_GROUPS,
	//		GDK_ACTION_MOVE);

	/*g_signal_connect(listbox, "drag-data-received",
			G_CALLBACK(passive_canvas_drag_data_received), NULL);

	gtk_tool_palette_add_drag_dest(GTK_TOOL_PALETTE(new_widget), listbox,
			GTK_DEST_DEFAULT_ALL, GTK_TOOL_PALETTE_DRAG_ITEMS, GDK_ACTION_COPY);*/

	gtk_widget_show_all(GTK_WIDGET(kwindow->window));
	k_window_signal_quit(kwindow);
	gtk_main();
	g_object_unref(kwindow);
	return 1;
}
