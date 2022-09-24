N = int(input())

tree = {}
for _ in range (N):
    root, left, right = map(str, input().split())
    tree[root] = [left, right]


def preorder(root):
    if root != '.':
        result.append(root)
        preorder(tree[root][0])
        preorder(tree[root][1])

def inorder(root):
    if root != '.':
        inorder(tree[root][0])
        result.append(root)
        inorder(tree[root][1])

def postorder(root):
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1])
        result.append(root)

result = []
preorder('A')
print(''.join(result))
result = []
inorder('A')
print(''.join(result))
result = []
postorder('A')
print(''.join(result))