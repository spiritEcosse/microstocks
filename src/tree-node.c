/* tree-node.c
 *
 * Copyright (C) 2017 igor <shevchenkcoigor@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <dazzle.h>
#include "tree-node.h"

struct _TreeNode
{
	GObject		parent_instance;
	DzlTree		*tree;
	GtkWidget	*panel;
};

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
	TreeNode *self;

	self->tree = g_object_new (TREE_TYPE_NODE,
				   "headers-visible", FALSE,
				   "level-indentation", 22,
				   "visible", TRUE,
				   NULL);

	root = dzl_tree_node_new ();
	dzl_tree_node_set_item (root, G_OBJECT (context));
	dzl_tree_set_root (DZL_TREE (self), root);
}

