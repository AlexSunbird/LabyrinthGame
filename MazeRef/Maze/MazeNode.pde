class Node {
  Node north = null;
  Node east = null;
  Node south = null;
  Node west = null;

  boolean isStart = false;
  boolean isFinish = false;

  int posX;
  int posY;
  int absPosX;
  int absPosY;

  boolean visited = false;
  boolean searched = false;
  boolean changed = false;

  Node(int posX, int posY)
  {
    this.posX = posX;
    this.posY = posY;
    this.absPosX = posX * NODE_SIZE;
    this.absPosY = posY * NODE_SIZE;
  }

  public void draw()
  {
    int offset = NODE_SIZE - 1;

    strokeWeight(3);
    fill(255);
    noStroke();
    rect(this.absPosX, this.absPosY, NODE_SIZE, NODE_SIZE);
    stroke(0);
    fill(0);

    if (this.north == null)
    {
      line(this.absPosX, this.absPosY, this.absPosX + offset, this.absPosY);
    }
    if (this.east == null && !this.isFinish)
    {
      line(this.absPosX + offset, this.absPosY, this.absPosX + offset, this.absPosY + offset);
    }
    if (this.south == null)
    {
      line(this.absPosX, this.absPosY + offset, this.absPosX + offset, this.absPosY + offset);
    }
    if (this.west == null && !this.isStart)
    {
      line(this.absPosX, this.absPosY, this.absPosX, this.absPosY + offset);
    }

    this.changed = false;
  }

  public void setDirection(Direction dir, Node node)
  {
    switch (dir) 
    {
    case NORTH: 
      this.north = node; 
      break;
    case EAST:  
      this.east = node;  
      break;
    case SOUTH: 
      this.south = node; 
      break;
    case WEST:  
      this.west = node;  
      break;
    }
  }

  public Node getDirection(Direction dir)
  {
    switch (dir)
    {
    case NORTH: 
      return this.north;
    case EAST:  
      return this.east;
    case SOUTH: 
      return this.south;
    case WEST:  
      return this.west;
    default:    
      return null;
    }
  }
}
