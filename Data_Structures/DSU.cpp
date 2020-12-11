//Basic 

void make_set(int v) {//creates a new set consisting of the new element v
    parent[v] = v;
}

int find_set(int v) {/// returns the representative (also called leader) of the set that contains the element v
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b) {//merges the two specified sets
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
///Using Path compression optimization
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
///Union by size:
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
/*
	When we perform a union operation between a higher heightened and a lower heightened tree,
 	if we merge a lower heightened tree as a parent of a higher heightened tree then it will increases the height of the tree. 
 	Instead, if we marge higher height tree as a parent of lower height tree then, height will not increase.
 	
 	So, we have to merge smaller into higher.
 */
 
///Union by rank based on the depth of the trees:
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
