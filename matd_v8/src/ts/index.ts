import { MatdV8 } from "./interfaces/MatdV8";

const {
  MatdV8,
}: {
  MatdV8: MatdV8;
} = require("../../../bin/Windows/Release/x64/Debug/matd_v8_bindings.node") as any;

export default MatdV8;
