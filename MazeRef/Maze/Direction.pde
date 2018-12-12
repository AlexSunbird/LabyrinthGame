public enum Direction {
  NORTH, 
    EAST, 
    SOUTH, 
    WEST, 
    INVALID
}

public ArrayList<Direction> directionList()
{
  ArrayList<Direction> directions = new ArrayList<Direction>();
  for(Direction dir : Direction.values())
  {
    directions.add(dir);
  }
  return directions;
}

public Direction getOpposite(Direction dir)
{
  switch(dir)
  {
  case NORTH: 
    return Direction.SOUTH;
  case EAST:
    return Direction.WEST;
  case SOUTH: 
    return Direction.NORTH;
  case WEST:  
    return Direction.EAST;
  default:    
    return Direction.INVALID;
  }
}

public int getDirectionX(Direction dir)
{
  switch(dir)
  {
  case EAST:  
    return 1;
  case WEST:  
    return -1;
  default:    
    return 0;
  }
}

public int getDirectionY(Direction dir)
{
  switch(dir)
  {
  case NORTH: 
    return -1;
  case SOUTH: 
    return 1;
  default:    
    return 0;
  }
}
