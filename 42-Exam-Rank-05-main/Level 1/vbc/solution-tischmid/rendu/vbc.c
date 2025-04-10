#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

typedef struct node {
	enum {
		ADD,
		MULTI,
		VAL
	}	type;
	int	val;
	struct node	*l;
	struct node	*r;
}		node;

node	*new_node(node n) {
	node *ret = calloc(1, sizeof(node));
	if (!ret)
		return NULL;
	*ret = n;
	return ret;
}

void	destroy_tree(node *n) {
	if (!n)
		return;
	if (n->type != VAL) {
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

int		accept(char **s, char c) {
	if (**s == c) {
		(*s)++;
		return 1;
	}
	return 0;
}

int expect(char **s, char c) {
	if (accept(s, c))
		return 1;
	unexpected(**s);
	return 0;
}

node	*parse_adds(char **s);

node	*parse_atomic(char **s) {
	if (!*s)
		return NULL;
	else if (accept(s, '(')) {
		node *tree = parse_adds(s);
		if (!expect(s, ')')) {
			destroy_tree(tree);
			return NULL;
		}
		return tree;
	} else if (isdigit(**s)) {
		return new_node((node){.type = VAL, .val = *((*s)++) - '0'});
	} else {
		unexpected(**s);
		return NULL;
	}
}

// parses all linear adds (i.e. 1*expr*42*expr*...*1)
node	*parse_mults(char **s) {
	node *left = parse_atomic(s);
	if (!left)
		return NULL;
	if (accept(s, '*')) {
		node *right = parse_mults(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		return new_node((node){.type = MULTI, .l = left, .r = right});
	} else {
		node *right = new_node((node){.type = VAL, .val = 1});
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		return new_node((node){.type = MULTI, .l = left, .r = right});
	}
}

// parses all linear adds (i.e. 1+expr+42+expr+...+1)
node	*parse_adds(char **s) {
	node *left = parse_mults(s);
	if (!left)
		return NULL;
	if (accept(s, '+')) {
		node *right = parse_adds(s);
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		return new_node((node){.type = ADD, .l = left, .r = right});
	} else {
		node *right = new_node((node){.type = VAL, .val = 0});
		if (!right) {
			destroy_tree(left);
			return NULL;
		}
		return new_node((node){.type = ADD, .l = left, .r = right});
	}
}

node	*parse_expr(char **s) {
	node *tree = parse_adds(s);
	if (!tree)
		return NULL;

	if (!expect(s, '\0')) {
		destroy_tree(tree);
		return NULL;
	}
	return tree;
}

int	eval_tree(node *tree) {
	switch (tree->type) {
		case ADD:
			return (eval_tree(tree->l) + eval_tree(tree->r));
		case MULTI:
			return (eval_tree(tree->l) * eval_tree(tree->r));
		case VAL:
			return tree->val;
	}
}

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	node *tree = parse_expr(&argv[1]);
	if (!tree)
		return 1;
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
}
