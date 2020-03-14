#include "stl_file.h"

stl_file stl_file_create(char *filename, char *name){
	stl_file s;
	s.name = name;
	s.file = fopen(filename, "w+");
	fprintf(s.file, "solid %s\n", name);
	return s;
}

void stl_file_close(stl_file *s){
	fprintf(s->file, "endsolid %s\n", s->name);
	fclose(s->file);
	s->name = NULL;
}

void stl_file_write_triangle(stl_file *s, triangle *t){
	point_3d normal = triangle_compute_normal(t);
	fprintf(s->file, "facet normal %e %e %e\n", normal.x, normal.y, normal.z);
	fprintf(s->file, "	outer loop\n");
	fprintf(s->file, "		vertex %e %e %e\n", t->v1.x, t->v1.y, t->v1.z);
	fprintf(s->file, "		vertex %e %e %e\n", t->v2.x, t->v2.y, t->v2.z);
	fprintf(s->file, "		vertex %e %e %e\n", t->v3.x, t->v3.y, t->v3.z);
	fprintf(s->file, "	endloop\n");
	fprintf(s->file, "endfacet\n");
}

void stl_file_create_and_write(char *filename, char *name,triangle *t, int num_triangles){
	stl_file s = stl_file_create(filename, name);
	for (int i = 0; i < num_triangles; i++)
		stl_file_write_triangle(&s, &t[i]);
	stl_file_close(&s);
}