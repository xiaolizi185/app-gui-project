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

	GtkWidget *listbox, *button;
	button = gtk_button_new();
	listbox = gtk_list_box_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	button = gtk_button_new();
	gtk_container_add(GTK_CONTAINER(listbox), GTK_WIDGET(button));
	gtk_container_add(GTK_CONTAINER(kwindow->sw2), GTK_WIDGET(listbox));

	gtk_widget_show_all(GTK_WIDGET(kwindow->window));
	k_window_signal_quit(kwindow);
	gtk_main();
	g_object_unref(kwindow);
	return 1;
}
