#include <dazzle.h>
#include "tree-node.h"

typedef struct
{

} TreeNodePrivate;

G_DEFINE_TYPE_WITH_PRIVATE (TreeNode, tree_node, G_TYPE_OBJECT)

enum {
	PROP_0,
	N_PROPS
};

static GParamSpec *properties [N_PROPS];

TreeNode *
tree_node_new (void)
{
	return g_object_new (TREE_TYPE_NODE, NULL);
}

static void
tree_node_finalize (GObject *object)
{
	TreeNode *self = (TreeNode *)object;
	TreeNodePrivate *priv = tree_node_get_instance_private (self);

	G_OBJECT_CLASS (tree_node_parent_class)->finalize (object);
}

static void
tree_node_get_property (GObject    *object,
                        guint       prop_id,
                        GValue     *value,
                        GParamSpec *pspec)
{
	TreeNode *self = TREE_NODE (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
tree_node_set_property (GObject      *object,
                        guint         prop_id,
                        const GValue *value,
                        GParamSpec   *pspec)
{
	TreeNode *self = TREE_NODE (object);

	switch (prop_id)
	  {
	  default:
	    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
	  }
}

static void
tree_node_class_init (TreeNodeClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = tree_node_finalize;
	object_class->get_property = tree_node_get_property;
	object_class->set_property = tree_node_set_property;
}

static void
tree_node_init (TreeNode *self)
{
}




static
void tree_addin_context_set () {
	GObject    *context;
	DzlTreeNode *root;

	root = dzl_tree_node_new ();
	dzl_tree_node_set_item (root, G_OBJECT (context));
	dzl_tree_set_root (DZL_TREE (self), root);
}

