type t = {
  name: string,
  icon: string,
  url: string,
};

let name = t => t.name;
let icon = t => t.icon;
let url = t => t.url;

let test = (value, url) => {
  let tester = Js.Re.fromString(value);
  url |> Js.Re.test_(tester);
};

let make = url => {
  let (icon, name) =
    switch (url) {
    | url when url |> test("twitter") => ("fab fa-twitter", "Twitter")
    | url when url |> test("facebook") => ("fab fa-facebook-f", "Facebook")
    | url when url |> test("instagram") => ("fab fa-instagram", "Instagram")
    | url when url |> test("youtube") => ("fab fa-youtube", "Youtube")
    | url when url |> test("linkedin") => ("fab fa-linkedin", "Linkedin")
    | url when url |> test("snapchat") => ("fab fa-snapchat", "Snapchat")
    | url when url |> test("tumblr") => ("fab fa-tumblr", "Tumblr")
    | url when url |> test("pinterest") => ("fab fa-pinterest", "Pinterest")
    | url when url |> test("reddit") => ("fab fa-reddit", "Reddit")
    | url when url |> test("flickr") => ("fab fa-flickr", "Flickr")
    | url when url |> test("messenger") => (
        "fab fa-facebook-messenger",
        "Messenger",
      )
    | url when url |> test("chat") => ("fab fa-facebook-messenger", "Chat")
    | url when url |> test("info") => ("fa fa-info-circle", "Info")
    | url when url |> test("github") => ("fab fa-github", "Github")
    | url when url |> test("play") => ("fab fa-google-play", "Google Play")
    | url when url |> test("npm") => ("fab fa-npm", "npm")
    | url when url |> test("medium") => ("fab fa-medium", "Medium")
    | unknownUrl => ("fas fa-external-link-square-alt", unknownUrl)
    };

  {name, icon, url};
};

let decodeArray = json => {
  json |> Json.Decode.array(Json.Decode.string) |> Array.map(make);
};
