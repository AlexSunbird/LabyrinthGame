public void generate()
{
  ArrayList<Node> todo = new ArrayList<Node>();

  int randX = int(random(0, MAZE_SIZE_X));
  int randY = int(random(0, MAZE_SIZE_Y));
  todo.add(nodes[randX][randY]);
  
  while (!todo.isEmpty())
  {
    Node currentNode = todo.get(todo.size() - 1);
    currentNode.visited = true;

    ArrayList<Direction> directions = directionList();
    Direction randomDir = Direction.INVALID;
    Node nextNode = null;

    while (!directions.isEmpty())
    {
      randomDir = directions.remove(int(random(0, directions.size())));
      int x = currentNode.posX + getDirectionX(randomDir);
      int y = currentNode.posY + getDirectionY(randomDir);

      if (x >= 0 && x < MAZE_SIZE_X && y >= 0 && y < MAZE_SIZE_Y)
      {
        Node tempNode = nodes[x][y];
        if (!tempNode.visited)
        {
          nextNode = tempNode;
          break;
        }
      }
    }

    if (nextNode != null)
    {
      todo.add(nextNode);
      carve(currentNode, nextNode, randomDir);
      //delay(STEP_MS);
    } else
    {
      todo.remove(currentNode);
    }
  }
  generatorFinished = true;
}

public void carve(Node source, Node target, Direction dir)
{
  source.setDirection(dir, target);
  target.setDirection(getOpposite(dir), source);
  source.changed = true;
  target.changed = true;
}
