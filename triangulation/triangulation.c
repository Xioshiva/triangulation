#include "triangulation.h"

double findMaxMin(vector_2d *p, char *search){
	double Res = 0;
	if(strcmp(search, "Xmax") == 0)
	{
		for (int i = 0; i < p->length; i++)
		{
			if(Res < p->content[i].x)
				Res = p->content[i].x;
		}
	}
	else if(strcmp(search, "Ymax") == 0)
	{
		for (int i = 0; i < p->length; i++)
		{
			if(Res < p->content[i].y)
				Res = p->content[i].y;
		}
	}
	else if(strcmp(search, "Xmin") == 0)
	{
		for (int i = 0; i < p->length; i++)
		{
			if(Res > p->content[i].x)
				Res = p->content[i].x;
		}
	}
	else if(strcmp(search, "Ymin") == 0)
	{
		for (int i = 0; i < p->length; i++)
		{
			if(Res > p->content[i].y)
				Res = p->content[i].y;
		}
	}
	return Res;
}

void add_super_triangle(vector_2d *p, vector_i_triangle *t){
	double xmax = findMaxMin(p, "Xmin");
	double ymax = findMaxMin(p, "Ymin");
	double xmin = findMaxMin(p, "Xmax");
	double ymin = findMaxMin(p, "Ymax");

	double dx = xmax - xmin; // valeur max de x - min de x des points
	double dy = ymax - ymin; // valeur max de y - min de y des points
	double dmax = (dx > dy) ? dx : dy;
	double xmid = (xmax + xmin) / 2.0;
	double ymid = (ymax + ymin) / 2.0;

	point_2d p0 = point_2d_create(xmid - 20 * dmax, ymid - dmax);
	point_2d p1 = point_2d_create(xmid, ymid + 20 * dmax);
	point_2d p2 = point_2d_create(xmid + 20 * dmax, ymid - dmax);

	vector_2d_push(p, p0);
	vector_2d_push(p, p1);
	vector_2d_push(p, p2);

	i_triangle temp_t = i_triangle_create(p->length - 1, p->length - 2, p->length - 3);
	vector_i_triangle_push(t, temp_t);
}

static bool is_inside_circum_circle_points(point_2d p0, 
    point_2d p1, point_2d p2, point_2d p3, 
    point_2d *pc, double *rsqr, double epsilon){

    double fabs_y1y2 = fabs(p1.y-p2.y);
    double fabs_y2y3 = fabs(p2.y-p3.y);

    /* Check for coincident points */
    if (fabs_y1y2 < epsilon && fabs_y2y3 < epsilon)
        return(false);

    if (fabs_y1y2 < epsilon) {
        double m2 = - (p3.x - p2.x) / (p3.y-p2.y);
        double mx2 = (p2.x + p3.x) / 2.0;
        double my2 = (p2.y + p3.y) / 2.0;
        pc->x = (p2.x + p1.x) / 2.0;
        pc->y = m2 * (pc->x - mx2) + my2;
    } else if (fabs_y2y3 < epsilon) {
        double m1 = - (p2.x-p1.x) / (p2.y-p1.y);
        double mx1 = (p1.x + p2.x) / 2.0;
        double my1 = (p1.y + p2.y) / 2.0;
        pc->x = (p3.x + p2.x) / 2.0;
        pc->y = m1 * (pc->x - mx1) + my1;
    } else {
        double m1 = - (p2.x-p1.x) / (p2.y-p1.y);
        double m2 = - (p3.x-p2.x) / (p3.y-p2.y);
        double mx1 = (p1.x + p2.x) / 2.0;
        double mx2 = (p2.x + p3.x) / 2.0;
        double my1 = (p1.y + p2.y) / 2.0;
        double my2 = (p2.y + p3.y) / 2.0;
        pc->x = (m1 * mx1 - m2 * mx2 + my2 - my1) / (m1 - m2);
        if (fabs_y1y2 > fabs_y2y3) {
            pc->y = m1 * (pc->x - mx1) + my1;
        } else {
            pc->y = m2 * (pc->x - mx2) + my2;
        }
    }

    double dx = p2.x - pc->x;
    double dy = p2.y - pc->y;
    *rsqr = dx*dx + dy*dy;

    dx = p0.x - pc->x;
    dy = p0.y - pc->y;
    double drsqr = dx*dx + dy*dy;

    return ((drsqr - *rsqr) <= epsilon);
}


void bowyer_watson(vector_2d *points, vector_i_triangle *vec_triangle){
	add_super_triangle(points, vec_triangle);

	vector_i_triangle very_bad_triangles;
	vector_i_triangle_init(&very_bad_triangles);
	vector_i_edge vec_edge;
	vector_i_edge_init(&vec_edge);
	i_edge *list_edge = malloc(sizeof(i_edge) * 3);
	double rsqr = 0;
	point_2d pc = point_2d_create(0,0);
	double epsilon = 0.1;


	for (int i = 0; i < points->length; i++)
	{
		vector_i_triangle_empty(&very_bad_triangles);
		//finding out bad triangles
		for (int j = 0; j < vec_triangle->length; j++)
		{
			if (is_inside_circum_circle_points(points->content[i], 
    		points->content[vec_triangle->content[j].p1], points->content[vec_triangle->content[j].p2], points->content[vec_triangle->content[j].p3],
    		&pc, &rsqr, epsilon))
			{
				vector_i_triangle_push(&very_bad_triangles, vec_triangle->content[j]);
			}
		}

		vector_i_edge_empty(&vec_edge);

		//stocking polygone around the "hole"
		for (int jj = 0; jj < very_bad_triangles.length; jj++)
		{
			list_edge[0] = i_edge_create(very_bad_triangles.content[jj].p1, very_bad_triangles.content[jj].p2);
			list_edge[1] = i_edge_create(very_bad_triangles.content[jj].p1, very_bad_triangles.content[jj].p3);
			list_edge[2] = i_edge_create(very_bad_triangles.content[jj].p2, very_bad_triangles.content[jj].p3);
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < very_bad_triangles.length; l++)
				{
					if(l == jj){
						l++;
						if (l == very_bad_triangles.length){
							vector_i_edge_push(&vec_edge ,list_edge[k]);
							break;
						}
					}
					if (find_edge_in_triangle(list_edge[k], very_bad_triangles.content[l]))
						break;
					if (l == very_bad_triangles.length - 1)
						vector_i_edge_push(&vec_edge ,list_edge[k]);
				}
			}
		}

		//removing bad triangles
		for (int jjj = 0; jjj < very_bad_triangles.length; jjj++)
		{
			for (int kk = 0; kk < vec_triangle->length; kk++)
			{
				if(i_triangle_are_equal(very_bad_triangles.content[jjj], vec_triangle->content[kk]))
					vector_i_triangle_remove(vec_triangle, kk);
			}
		}

		//making new triangles
		for (int jo = 0; jo < vec_edge.length; jo++)
		{
			i_triangle temp_i_t = form_i_triangle_from_edge_and_point(vec_edge.content[jo], i);
			vector_i_triangle_push(vec_triangle, temp_i_t);
		}


	}
	//removing super triangle
	i_triangle super_triangle = i_triangle_create(points->length - 1, points->length - 2, points->length - 3);
	int kek = vec_triangle->length;
	for (int ii = 0; ii < kek; ii++)
	{
		if(i_triangle_in_i_triangle(vec_triangle->content[ii], super_triangle)){
			vector_i_triangle_remove(vec_triangle, ii);
			ii--;
		}
	}
	free(list_edge);
	vector_i_triangle_free(&very_bad_triangles);
	vector_i_edge_free(&vec_edge);
}