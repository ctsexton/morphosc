#include <geometry.h>
#include <math.h>
#include <sensel.h>

float distance(float centroid[2], float coordinate[2])
{
  return hypot(coordinate[0] - centroid[0], coordinate[1] - centroid[1]);
}

float stretch(SenselFrameData *frame) {
  float sum_x = 0;
  float sum_y = 0;
  float sum_distance = 0;
  float ave_x;
  float ave_y;
  float ave_distance;
  float centroid[2];
  for (int i = 0; i < frame->n_contacts; i++)
  {
    sum_x += frame->contacts[i].x_pos;
    sum_y += frame->contacts[i].y_pos;
  };
  ave_x = sum_x / frame->n_contacts;
  ave_y = sum_y / frame->n_contacts;
  centroid[0] = ave_x;
  centroid[1] = ave_y;
  for (int j = 0; j < frame->n_contacts; j++)
  {
    float position[] = {frame->contacts[j].x_pos, frame->contacts[j].y_pos};
    sum_distance += distance(centroid, position);
  };
  ave_distance = sum_distance / frame->n_contacts;
  return ave_distance;
}
