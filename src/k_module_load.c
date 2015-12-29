#include "k_module_load.h"

void load_main(KWindow* kwindow) {
	GDir *dir;
	GtkWidget *tool_palette,*listbox;

	const gchar *file_name;
	dir = g_dir_open(MAIN_LIB, 0, NULL);
	file_name = g_dir_read_name(dir);
	while (file_name != NULL) {
		if (file_name[0] != '.') {
			gchar *path = g_build_filename(MAIN_LIB, file_name, NULL);
			GModule* test_model = g_module_open(path, G_MODULE_BIND_LAZY);
			g_module_symbol(test_model, "k_new_object",
					(gpointer *) &new_object);
			gpointer newobject = new_object();

			g_module_symbol(test_model, "k_get_widget",
					(gpointer *) &get_widget);
			GtkWidget *new_widget = get_widget(newobject);
			g_module_symbol(test_model, "get_index", (gpointer *) &get_index);
			gint index = get_index();
			if (index == 1) {
				gtk_box_pack_start(GTK_BOX(kwindow->menubarview),
						GTK_WIDGET(new_widget),
						FALSE, TRUE, 2);
			} else if (index == 2) {
				gtk_box_pack_start(GTK_BOX(kwindow->menubarview),
						GTK_WIDGET(new_widget),
						FALSE, TRUE, 1);
			} else if (index == 3) {
				gtk_container_add(GTK_CONTAINER(kwindow->sw1),
						GTK_WIDGET(new_widget));
				tool_palette = new_widget;
			}else if(index == 4){
				gtk_paned_add2(kwindow->paned,GTK_WIDGET(new_widget));
				g_module_symbol(test_model, "get_main_object", (gpointer *) &get_main_object);
				gpointer object  = get_main_object(newobject);
				listbox = GTK_WIDGET(object);
			}
		}
		file_name = g_dir_read_name(dir);
	}

	gtk_tool_palette_add_drag_dest(GTK_TOOL_PALETTE(tool_palette), listbox,
				GTK_DEST_DEFAULT_ALL, GTK_TOOL_PALETTE_DRAG_ITEMS, GDK_ACTION_COPY);
	g_dir_close(dir);
}
void load_menu_bar() {

}
void load_tools_bar() {

}
void load_status_bar() {

}
