#include "auxiliares.h"

float angulo_entre_vetores(Ponto* p1, Ponto* p2){
    float produto_interno, norma_p1, norma_p2, ang;

    produto_interno = (p1->x * p2->x) + (p1->y * p2->y);
    norma_p1 = sqrt(pow(p1->x, 2) + pow(p1->y, 2));
    norma_p2 = sqrt(pow(p2->x, 2) + pow(p2->y, 2));

    ang = produto_interno/(norma_p1*norma_p2);
    ang = acosf(ang)*180/3.1415;

    return ang;
}

float distancia_entre_pontos(Ponto* p1, Ponto* p2){
    float px, py, ang;

    px = pow(p1->x - p2->x, 2);
    py = pow(p1->y - p2->y, 2);

    ang = sqrt(px + py);

    return ang;
}
