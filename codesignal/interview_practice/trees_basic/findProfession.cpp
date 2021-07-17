string findProfession(int level, int pos) {
    bool is_E = true;
    while(level > 1) {
        int half_nodes = (1 << (level-2));
        if(pos > half_nodes) {
            pos -= half_nodes;
            is_E = !is_E;
        }
        --level;
    }
    return is_E? "Engineer":"Doctor";
}

// suffix 0 at left child, 1 at right child, root is 0
string findProfession(int level, int pos) {
    bool is_E = true;
    --pos;
    while(pos) {
        if(pos & 1) {
            is_E = !is_E;
        }
        pos >>= 1;
    }
    return is_E? "Engineer":"Doctor";
}


