#define INIT_SNAP_SIZE 10

typedef struct {
    int ***table;
    int *size;
    int snap_id;
    int snap_size;
} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {
    int i, j;
    SnapshotArray *obj = (SnapshotArray *)malloc(sizeof(SnapshotArray));
    obj->snap_id = 0;
    obj->snap_size = INIT_SNAP_SIZE;
    obj->table = (int ***)malloc(sizeof(int **) * length);
    for (i=0; i<length; i++) {
        obj->table[i] = (int **)malloc(sizeof(int *) * obj->snap_size);
        for (j=0; j<obj->snap_size; j++) {
            obj->table[i][j] = calloc(2, sizeof(int));
        }
    }
    obj->size = (int *)malloc(sizeof(int) * length);
    for (i=0; i<length; i++)
        obj->size[i] = 1;
    return obj;
}

void snapshotArraySet(SnapshotArray* obj, int index, int val) {
    int i, size = obj->size[index];

    if (obj->table[index][size-1][0] == obj->snap_id) {
        obj->table[index][size-1][1] = val;
        return;
    }

    if (obj->size[index] == obj->snap_size) {
         obj->table[index] = (int **)realloc(obj->table[index], sizeof(int *) * (obj->snap_size * 2));
         for (i=obj->snap_size; i<obj->snap_size*2; i++)
            obj->table[index][i] = calloc(2, sizeof(int));

        obj->snap_size *= 2;
    }

    obj->table[index][size][0] = obj->snap_id;
    obj->table[index][size][1] = val;
    obj->size[index]++;
}

int snapshotArraySnap(SnapshotArray* obj) {
    return obj->snap_id++;
}

int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id) {
    int left, right, mid;

    left = 0;
    right = obj->size[index] - 1;
    while (left < right) {
        mid = left + (right - left + 1) / 2;
        if (obj->table[index][mid][0] <= snap_id)
            left = mid;
        else
            right = mid - 1;
    }

    return obj->table[index][left][1];
}

void snapshotArrayFree(SnapshotArray* obj) {
    free(obj);
}