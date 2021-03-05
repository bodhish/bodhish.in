module.exports = {
  theme: {},
  variants: {},
  plugins: [],
  purge: {
    content: [
      "./src/**/*.html",
      "./src/**/*.res",
      "./src/**/*.bs.js",
      "./packages/mytemplate/src/**/*.res",
      "./packages/mytemplate/src/**/*.bs.js",
    ],

    options: {
      safelist: [/^bg-/, /^text-/, /^border-/, /^hover:/],
    },
  },
};

// Add the following if you want to whitelist classes
// options: {
//   whitelistPatterns: [/^bg-/, /^text-/, /^border-/, /^hover:/],
// },
