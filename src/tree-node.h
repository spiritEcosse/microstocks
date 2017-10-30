/* tree-node.h
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

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <glib-object.h>
#include <dazzle.h>

G_BEGIN_DECLS

#define TREE_TYPE_NODE (tree_node_get_type())

G_DECLARE_FINAL_TYPE (TreeNode, tree_node, TREE, NODE, DzlTreeNode)

TreeNode *tree_node_new (void);

G_END_DECLS

#endif /* TREE_NODE_H */


