#include "i_triangle/i_triangle.h"
#include "vector_2d/vector_2d.h"
#include "vector_3d/vector_3d.h"
#include "vector_i_triangle/vector_i_triangle.h"
#include "read_lidar/read_lidar.h"
#include "triangulation/triangulation.h"
#include "stl_file/stl_file.h"
#include "triangle/triangle.h"
#include <time.h>
#include <stdbool.h>
#include <string.h>

bool test_arguments(int argc, char *argv[]){
    if (argc != 4){
        printf("Wrong number of arguments.\n");
        return 0;
    }
    if(strstr(argv[1], ".las") == NULL){
        printf("First argument is not a .las file.\n");
        return 0;
    }
    if (atof(argv[2]) > 1 || atof(argv[2]) <= 0){
        printf("Filter number out of bounds\n");
        return 0;
    }
    if(strstr(argv[3], ".stl") == NULL){
        printf("Third argument is not a .stl file.\n");
        return 0;
    }
    return 1;
}

int *make_filter_list(double probability, uint32_t num_points){//makes list to filet points
    
    srand(time(NULL));
    int *list_int = malloc(sizeof(int) * num_points);
    for (uint32_t i = 0; i < num_points; ++i)
    {
        double random = rand()/(double)RAND_MAX / 1;
        if (random < probability)
            list_int[i] = 1;
        else
            list_int[i] = 0;
    }
    return list_int;
}

int main(int argc, char *argv[]){

    if(!test_arguments(argc, argv))
        return 0;

	vector_2d p2d;
	vector_2d_init(&p2d);
	vector_3d p3d;
	vector_3d_init(&p3d);
	vector_i_triangle t;
	vector_i_triangle_init(&t);


	header h = header_from_file(argv[1]);
	point_3d *list_3d = points_from_file(argv[1], h, &h.num_point_records);
    point_3d_print(&list_3d[0]);
    point_3d_print(&list_3d[1]);
    point_3d_print(&list_3d[2]);


    int *filter_list = make_filter_list(atof(argv[2]), h.num_point_records);
	vector_2d_from_list_with_filter(list_3d, &p2d, h.num_point_records/2, filter_list); // For some reason num_points_record is multiplied by 2
	vector_3d_from_list_with_filter(list_3d, &p3d, h.num_point_records/2, filter_list);
	

	bowyer_watson(&p2d, &t);

	
	triangle *tlist = triangle_from_i_triangle(&p3d, t);
	stl_file_create_and_write(argv[3], "kek", tlist, t.length);


    free(tlist);
    vector_2d_free(&p2d);
    vector_3d_free(&p3d);
    vector_i_triangle_free(&t);
    free(filter_list);
    free(list_3d);
    return 0;
}