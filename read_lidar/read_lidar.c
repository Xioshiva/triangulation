#include "read_lidar.h"

header header_from_file(char *fname){
	FILE* myLidarFile;
	header h;
	int error;
	myLidarFile = fopen(fname, "rb");
	error = fread(&h, sizeof(header), 1, myLidarFile);
	fclose(myLidarFile);
	return(h);
}


void print_header(header *h){
	printf("%s\n", h->signature);
	printf("%u\n", h->source_id);
	printf("%u\n", h->global_encoding);
	printf("%u\n", h->pid_data_1);
	printf("%u\n", h->pid_data_2);
	printf("%u\n", h->pid_data_3);
	for (int i = 0; i < 8; ++i)
	{
		printf("%u\n",  h->pid_data_4[i]);
	}
	printf("%u\n", h->version_major);
	printf("%u\n", h->version_minor);
	printf("%s\n", h->system_id);
	printf("%s\n", h->gen_soft);
	printf("%u\n", h->creation_day);
	printf("%u\n", h->creation_year);
	printf("%u\n", h->header_size);
	printf("%u\n", h->off_to_point_data);
	printf("%u\n", h->num_var_length_record);
	printf("%u\n", h->point_data_format_id);
	printf("%u\n", h->point_data_record_length);
	printf("%u\n", h->num_point_records);
	for (int i = 0; i < 5; ++i)
	{
		printf("%u\n", h->num_points_by_return[i]);
	}
	printf("%f\n", h->x_scale_factor);
	printf("%f\n", h->y_scale_factor);
	printf("%f\n", h->z_scale_factor);
	printf("%f\n", h->x_offset);
	printf("%f\n", h->y_offset);
	printf("%f\n", h->z_offset);
	printf("%f\n", h->max_x);
	printf("%f\n", h->min_x);
	printf("%f\n", h->max_y);
	printf("%f\n", h->min_y);
	printf("%f\n", h->max_z);
	printf("%f\n", h->min_z);
}



point_3d *points_from_file(char *fname, header h, uint32_t *num_points){
	FILE* myLidarFile;
	point_3d * list_pt3d = malloc(sizeof(point_3d) * h.num_point_records);
	point_record_1 * ptr1 = malloc(sizeof(point_record_1) * h.num_point_records);
	myLidarFile = fopen(fname, "rb");
	int error;
	fseek(myLidarFile, h.off_to_point_data, SEEK_CUR);
	for (uint32_t i = 0; i < h.num_point_records; i++)
	{
		error = fread(&ptr1[i], sizeof(point_record_1), 1, myLidarFile);
		*num_points += 1;
	}
	for (uint32_t i = 0; i < h.num_point_records; i++)
	{
		list_pt3d[i].x = ptr1[i].x * h.x_scale_factor + h.x_offset;
		list_pt3d[i].y = ptr1[i].y * h.y_scale_factor + h.y_offset;
		list_pt3d[i].z = ptr1[i].z * h.z_scale_factor + h.z_offset;
	}
	free(ptr1);
	fclose(myLidarFile);
	return list_pt3d;
}

void vector_2d_from_list(point_3d *list_pt3d, vector_2d *v,  uint32_t num_points){
	double x, y;
	for (uint32_t i = 0; i < num_points; i++)
	{
		x = list_pt3d[i].x;
		y = list_pt3d[i].y;
		point_2d kek = point_2d_create(x,y);
		vector_2d_push(v, kek);
	}
}

void vector_3d_from_list(point_3d *list_pt3d, vector_3d *v,  uint32_t num_points)
{
	double x, y, z;
	for (uint32_t i = 0; i < num_points; i++)
	{
		x = list_pt3d[i].x;
		y = list_pt3d[i].y;
		z = list_pt3d[i].z;
		point_3d kek = point_3d_create(x,y,z);
		vector_3d_push(v, kek);
	}
}


void vector_2d_from_list_with_filter(point_3d *list_pt3d, vector_2d *v,  uint32_t num_points, int *list_filter){
	double x, y;
	for (uint32_t i = 0; i < num_points; i++)
	{
		if (list_filter[i] == 1)
		{
			x = list_pt3d[i].x;
			y = list_pt3d[i].y;
			point_2d kek = point_2d_create(x,y);
			vector_2d_push(v, kek);
		}
	}
}

void vector_3d_from_list_with_filter(point_3d *list_pt3d, vector_3d *v,  uint32_t num_points, int *list_filter){
	double x, y, z;
	for (uint32_t i = 0; i < num_points; i++)
	{
		if (list_filter[i] == 1)
		{
			x = list_pt3d[i].x;
			y = list_pt3d[i].y;
			z = list_pt3d[i].z;
			point_3d kek = point_3d_create(x,y,z);
			vector_3d_push(v, kek);
		}
	}
}


void print_point_record(point_record_1 *p){
	printf("x = %u y = %u z = %u \n",p->x, p->y, p->z);
	printf("%u\n", p->intensity);
	printf("%u\n", p->flags);
	printf("%u\n", p->classification);
	printf("%u\n", p->scan_angle_rank);
	printf("%u\n", p->user_data);
	printf("%u\n", p->point_source_id);
	printf("%f\n", p->gps_time);
}