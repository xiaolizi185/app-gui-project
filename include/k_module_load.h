#include <gmodule.h>
#include <gtk/gtk.h>
#include "kwindow.h"
#define MAIN_LIB  "./main_libs"
#define TOOL_BAR_LIB  "./tool_libs"
#define MENU_BAR_LIB "./menu_libs"
#define STATUS_BAR_LIB "./statusbar_libs"

typedef gpointer (*NewBoject)();
NewBoject new_object;

typedef GtkWidget* (*GetWidget)(gpointer);
GetWidget get_widget;

typedef gint (*GetIndex)();
GetIndex get_index;
void load_main(KWindow* kwindow);
void load_menu_bar();
void load_tools_bar();
void load_status_bar();

