const path = require('path');
const NodemonPlugin = require( 'nodemon-webpack-plugin' )
const nodeExternals = require('webpack-node-externals');

module.exports = {
  entry: './v8_bindings/src/ts/index.ts',
  devtool: 'inline-source-map',
  module: {
    rules: [
      {
        test: /\.tsx?$/,
        use: 'ts-loader',
        exclude: /node_modules/
      },
      {
        "test": /\.node$/,
        "use": {
          loader: "node-loader"
        }
      },
    ]
  },
  resolve: {
    extensions: [ '.tsx', '.ts', '.js' ],
    alias: {
      "mdLib": "./build/Release/md_node_bindings.node"
    }
  },
  output: {
    filename: 'bundle.js',
    path: path.resolve(__dirname, 'dist')
  },
  plugins: [
    new NodemonPlugin()
  ],
  target: 'node', // in order to ignore built-in modules like path, fs, etc.
  externals: [nodeExternals()], // in order to ignore all modules in node_modules folder
  watchOptions: {
    poll: true
  }
};