#ifndef INCLUDE_K_TASK_TREEVIEW_H_
#define INCLUDE_K_TASK_TREEVIEW_H_

#include <gtk/gtk.h>
G_BEGIN_DECLS


enum {
	PROCESS_NAME = 0,
	PROCESS_ICON,
	PROCESS_STATUS,
	PROCESS_REQ_START,
	PROCESS_START,
	PROCESS_END,
	PROCESS_ID,
	PROCESS_RESULT,
	PROCESS_COLUMNS
};

#define TASK_DONE "已完成"
#define TASK_DOING "正在处理"
#define TASK_SUSPEND "等待处理"
#define TASK_ERROR "失败"

typedef struct _KTaskTreeview KTaskTreeview;
typedef struct _KTaskTreeviewClass KTaskTreeviewClass;

#define G_TYPE_K_TASK_TREEVIEW                         (k_task_treeview_get_type ())
#define K_TASK_TREEVIEW(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_K_TASK_TREEVIEW, KTaskTreeview))
#define IS_K_TASK_TREEVIEW(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_K_TASK_TREEVIEW))
#define K_TASK_TREEVIEW_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_K_TASK_TREEVIEW, KTaskTreeviewClass))
#define IS_K_TASK_TREEVIEW_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_K_TASK_TREEVIEW))
#define K_TASK_TREEVIEW_GET_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_K_TASK_TREEVIEW, KTaskTreeviewClass))

struct _KTaskTreeview {
    GObject object;
    GtkTreeView *treeview;
    GtkListStore *liststore;
    GtkFrame *frame;
    GtkBuilder* builder;
    GHashTable *cache_table;
    GHashTable *tree_table;
    guint g_timeout_id;
    GMutex mutex;
};

struct _KTaskTreeviewClass{
    GObjectClass parent_class;
};

GType k_task_treeview_get_type(void);
void k_task_treeview_class_init(KTaskTreeviewClass *klass);
void k_task_treeview_init(KTaskTreeview *k_task_treeview);
void k_task_treeview_dispose(GObject *object);

KTaskTreeview* k_task_treeview_new();

KTaskTreeview *k_task_treeview;
typedef struct _KTaskTreeviewValue KTaskTreeviewValue;
typedef struct _KTaskTreeviewValueClass KTaskTreeviewValueClass;

#define G_TYPE_K_TASK_TREEVIEW_VALUE                         (k_task_treeview_value_get_type ())
#define K_TASK_TREEVIEW_VALUE(instance)                      (G_TYPE_CHECK_INSTANCE_CAST ((instance), G_TYPE_K_TASK_TREEVIEW_VALUE, KTaskTreeviewValue))
#define IS_K_TASK_TREEVIEW_VALUE(instance)                   (G_TYPE_CHECK_INSTANCE_TYPE ((instance), G_TYPE_K_TASK_TREEVIEW_VALUE))
#define K_TASK_TREEVIEW_VALUE_CLASS(instanceklass)           (G_TYPE_CHECK_CLASS_CAST ((instanceklass), G_TYPE_K_TASK_TREEVIEW_VALUE, KTaskTreeviewValueClass))
#define IS_K_TASK_TREEVIEW_VALUE_CLASS(instanceklass)        (G_TYPE_CHECK_CLASS_TYPE ((instanceklass), G_TYPE_K_TASK_TREEVIEW_VALUE))
#define K_TASK_TREEVIEW_GET_VALUE_CLASS(instance)            (G_TYPE_INSTANCE_GET_CLASS ((instance), G_TYPE_K_TASK_TREEVIEW_VALUE, KTaskTreeviewValueClass))

struct _KTaskTreeviewValue {
    GObject object;
    gchar *task_name;
    gchar *status;
    gchar *req_start_time;
    gchar *start_time;
    gchar *end_time;
    gpointer result;
};

struct _KTaskTreeviewValueClass{
    GObjectClass parent_class;
};

GType k_task_treeview_value_get_type(void);
void k_task_treeview_value_class_init(KTaskTreeviewValueClass *klass);
void k_task_treeview_value_init(KTaskTreeviewValue *k_task_treeview);
void k_task_treeview_value_dispose(GObject *object);

KTaskTreeviewValue* k_task_treeview_value_new();


gchar *task_suspend(gchar *taskname, gpointer userdata);
void task_processing(gchar *uuid, gpointer userdata);
void task_done(gchar *uuid, gpointer userdata, gpointer ret);
G_END_DECLS

#endif /* INCLUDE_K_TASK_TREEVIEW_H_ */
