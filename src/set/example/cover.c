#include "cover.h"

int cover(Set *members, Set *subsets, Set *covering) {
    Set intersection;
    Kset *subset;
    ListElmt *member, *max_member;
    void *data;
    int max_size;

    set_init(covering, subsets->match, NULL);

    while (set_size(members) > 0 && set_size(subsets) > 0) {
        max_size = 0;

        for (member = list_head(subsets); member != NULL; member = list_next(member)) {
            if (set_intersection(&intersection, &((Kset *) list_data(member))->set, members) != 0)
                return -1;

            if (set_size(&intersection) > max_size) {
                max_member = member;
                max_size = set_size(&intersection);
            }

            set_destroy(&intersection);
        }

        if (max_size == 0)
            return -1;

        subset = (Kset *) list_data(max_member);

        if (set_insert(covering, subset) != 0)
            return -1;

        for (member = list_head(&((Kset *) list_data(max_member))->set); member != NULL; member = list_next(member)) {
            data = list_data(member);

            if (set_remove(members, (void **) &data) == 0 && members->destroy != NULL)
                members->destroy(data);
        }

        if (set_remove(subsets, (void **) &subset) != 0)
            return -1;
    }

    if (set_size(members) > 0)
        return -1;

    return 0;
}