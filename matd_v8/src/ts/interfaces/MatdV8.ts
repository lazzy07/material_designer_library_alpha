export interface MatdV8 {
  new (): MatdV8;
  parseJSONToNodeGraph: (nodeGraphString: string) => void;
}
