#ifndef INCLUDE_DIALOG_CALLBACK_H_
#define INCLUDE_DIALOG_CALLBACK_H_

#include "k_list.h"
#include "k_call_rpc_function.h"
#include "common.h"
#include "k_import_export.h"
G_BEGIN_DECLS


/*network dialog method define*/

void callback_create_bond(GtkWidget *button, gpointer userdata);
void callback_delete_bond(GtkWidget *button, gpointer userdata);

G_END_DECLS

#endif /* INCLUDE_DIALOG_CALLBACK_H_ */
