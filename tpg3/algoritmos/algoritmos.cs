struct pt {
    mp mapa;
    coordenada jugador;
    array[0...c] de bool chocolates;
    nat cantMov;
    nat inmunidad;
    bool gano;
    bool perdio;
}

nuevaPartida(in m:mapa) -> res: pt
{
    pt partida;

    partida.mapa <- m;
    partida.jugador <- inicio(m);
	for(int i <- 0; i < cantChocolates(m); i++)
	{
		partida.chocolates[i] <- true;
	}
    partida.cantMov <- 0;

    int idChocolate <- mapa.idChocolate(mapa, partida.jugador);
    bool hayUnChocolate <- 0 <= idChocolate < mapa.cantChocolates(partida.m);
    if(hayUnChocolate)
    {
        partida.chocolates[idChocolate] <- false;
        partida.inmunidad <- 10;
    }
    else
    {
        partida.inmunidad <- 0;
    }

    partida.perdio <- esCasilleroPeligroso(m, partida.jugador) && partida.inmunidad = 0;
    partida.gano <- llegada(m) = partida.jugador;
    
    res <- partida;
}

mover(in/out p: partida, in d: dirección)
{
    tupla<nat, nat> desplazamiento <- (0,0); 
    switch(d)
    {
        case ARRIBA:
            desplazamiento <- (0,1);
        case ABAJO:
            desplazamiento <- (0,-1);
        case IZQUIERDA:
            desplazamiento <- (-1,0);
        case DERECHA:
            desplazamiento <- (1,0);
    }
    tupla<nat, nat> nuevaPosición <- partida.jugador + desplazamiento;

    if(!esPared(partida.mapa, nuevaPosición) && enRango(partida.mapa, nuevaPosición))
    {
        partida.jugador <- nuevaPosición;
        partida.cantMov++;
        
        int idChocolate <- mapa.idChocolate(mapa, partida.jugador);
        bool hayUnChocolate <- 0 <= idChocolate < mapa.cantChocolates(partida.m);
        if(hayUnChocolate && partida.chocolates[idChocolate])
        {
            partida.chocolates[idChocolate] <- false;
            partida.inmunidad <- 10;
        }
        else
        {
            partida.inmunidad <- max(partida.inmunidad-1, 0);
        }

        partida.perdio <- mapa.esCasilleroPeligroso(m, partida.jugador) && partida.inmunidad == 0;
        partida.gano <- llegada(m) == partida.jugador;
    }
}

gano?(in p:partida) -> res: bool
{
    res <- partida.gano;
}

perdio?(in p:partida) -> res: bool
{
    res <- partida.perdio;
}

jugador(in p:partida) -> res: coordenada
{
    res <- partida.jugador;
}

cantMov(in p:partida) -> res: nat
{
    res <- partida.cantMov;
}
