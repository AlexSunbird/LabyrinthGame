ArrayList<Node> searchPath(Node source, Node target) //<>//
{
  ArrayList<Node> queue = new ArrayList<Node>();
  HashMap<Node, Node> parentNodes = new HashMap<Node, Node>();

  source.searched = true;
  parentNodes.put(source, source);
  queue.add(source);

  // Breadth-first-search
  while (!queue.isEmpty())
  {
    Node currentNode = queue.remove(0);

    ArrayList<Direction> directions = directionList();

    while (!directions.isEmpty())
    {
      Node childNode = currentNode.getDirection(directions.remove(0));
      if (childNode != null && childNode.searched == false)
      {
        childNode.searched = true;
        parentNodes.put(childNode, currentNode);
        queue.add(childNode);
      }
    }
  }

  // Backtrack
  Node currentPathNode = target;
  ArrayList<Node> path = new ArrayList<Node>();
  while (parentNodes.get(currentPathNode) != currentPathNode)
  {
    path.add(currentPathNode);
    currentPathNode = parentNodes.get(currentPathNode);
  }
  path.add(currentPathNode);

  searchFinished = true;
  return path;
}

void drawPath(ArrayList<Node> path)
{
  int offset = int(NODE_SIZE / 2);
  
  for (int i = 0; i < path.size() - 1; i++)
  {
    Node currentNode = path.get(i);
    Node nextNode = path.get(i + 1);
    
    stroke(255, 0, 0);
    strokeWeight(3);
    line(currentNode.absPosX + offset, currentNode.absPosY + offset, nextNode.absPosX + offset, nextNode.absPosY + offset);
  }
}
