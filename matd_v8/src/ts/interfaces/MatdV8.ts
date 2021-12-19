export interface MatdV8 {
  new (): MatdV8;
  parseJSONToNodeGraph: (nodeGraphString: string) => void;
  setComputationDevice: (platform: number, device: number) => void;
  getAvailableEngines: () => string[];
}
