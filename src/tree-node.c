#include <gtk/gtk.h>

static void
gb_project_tree_addin_context_set (GtkWidget  *widget,
                                   IdeContext *context)
{
	GbProjectTree *project_tree = (GbProjectTree *)widget;

	g_assert (GB_IS_PROJECT_TREE (project_tree));
	g_assert (!context || IDE_IS_CONTEXT (context));

	gb_project_tree_set_context (project_tree, context);

	root = dzl_tree_node_new ();
	dzl_tree_node_set_item (root, G_OBJECT (context));
	dzl_tree_set_root (DZL_TREE (self), root);
}

