#include <gtk/gtk.h>
#include <dazzle.h>

static void
tree_addin_context_set ()
{
	DzlTreeNode *root;

	root = dzl_tree_node_new ();
	dzl_tree_node_set_item (root, G_OBJECT (context));
	dzl_tree_set_root (DZL_TREE (self), root);
}
